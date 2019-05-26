#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/bind_executor.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "../../Controller.h"
#include "Listener.h"


using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

// Return a reasonable mime type based on the extension of a file.
boost::beast::string_view mimeType(boost::beast::string_view path) {
    using boost::beast::iequals;

    auto const ext = [&path] {
        auto const pos = path.rfind(".");
        if (pos == boost::beast::string_view::npos)
            return boost::beast::string_view{};
        return path.substr(pos);
    }();

    if (iequals(ext, ".htm")) return "text/html";
    if (iequals(ext, ".html")) return "text/html";
    if (iequals(ext, ".php")) return "text/html";
    if (iequals(ext, ".css")) return "text/css";
    if (iequals(ext, ".txt")) return "text/plain";
    if (iequals(ext, ".js")) return "application/javascript";
    if (iequals(ext, ".json")) return "application/json";
    if (iequals(ext, ".xml")) return "application/xml";
    if (iequals(ext, ".png")) return "image/png";
    if (iequals(ext, ".jpe")) return "image/jpeg";
    if (iequals(ext, ".jpeg")) return "image/jpeg";
    if (iequals(ext, ".jpg")) return "image/jpeg";

    return "application/text";
}

// Append an HTTP rel-path to a local filesystem path.
// The returned path is normalized for the platform.
std::string pathCat(boost::beast::string_view base, boost::beast::string_view path) {
    if (base.empty())
        return path.to_string();
    std::string result = base.to_string();

    char constexpr path_separator = '/';
    if (result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());

    return result;
}

template <class Body, class Allocator, class Send>
void handleRequest(boost::beast::string_view docRoot, http::request<Body, http::basic_fields<Allocator>>&& req,
                   Send&& send) {
    // Returns a bad request response
    auto const bad_request = [&req](boost::beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = why.to_string();
        res.prepare_payload();
        return res;
    };

    // Returns a not found response
    auto const not_found = [&req](boost::beast::string_view target) {
        http::response<http::string_body> res{http::status::not_found, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "The resource '" + target.to_string() + "' was not found.";
        res.prepare_payload();
        return res;
    };

    // Returns a server error response
    auto const server_error = [&req](boost::beast::string_view what) {
        http::response<http::string_body> res{http::status::internal_server_error, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "An error occurred: '" + what.to_string() + "'";
        res.prepare_payload();
        return res;
    };

    // Make sure we can handle the method
    if (req.method() != http::verb::get && req.method() != http::verb::head) {
        return send(bad_request("Unknown HTTP-method"));
    }

    // Request path must be absolute and not contain "..".
    if (req.target().empty() || req.target()[0] != '/' ||
        req.target().find("..") != boost::beast::string_view::npos) {
        return send(bad_request("Illegal request-target"));
    }

    // Routing
    http::string_body::value_type body;

    if (req.target() == "/task") {
        Controller c;
        Request r;

        std::string page = c.task(r);

        for (auto& c : page) {
            body.push_back(c);
        }
    } else {
        return send(not_found(req.target()));
    }

    // Cache the size since we need it after the move
    auto const size = body.length();

    // Respond to HEAD request
    if (req.method() == http::verb::head) {
        http::response<http::empty_body> res{http::status::ok, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.content_length(size);
        res.keep_alive(req.keep_alive());
        return send(std::move(res));
    }

    // Respond to GET request
    http::response<http::string_body> res{std::piecewise_construct,
                                          std::make_tuple(std::move(body)),
                                          std::make_tuple(http::status::ok, req.version())};


    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/html");
    res.content_length(size);
    res.keep_alive(req.keep_alive());

    return send(std::move(res));
}


int main(int argc, char* argv[]) {
//    if (argc != 5) {
//        std::cerr <<
//                  "Usage: server <address> <port> <docRoot> <threads>\n" <<
//                  "Example:\n" <<
//                  "    http-server-async 0.0.0.0 8080 . 1\n";
//        return EXIT_FAILURE;
//    }

//    auto const address = boost::asio::ip::make_address(argv[1]);
//    auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
//    auto const docRoot = std::make_shared<std::string>(argv[3]);
//    auto const threads = std::max<int>(1, std::atoi(argv[4]));

    auto const address = boost::asio::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(std::atoi("8000"));
    auto const docRoot = std::make_shared<std::string>(".");
    auto const threads = std::max<int>(1, std::atoi("4"));

    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

    // Create and launch a listening port
    std::make_shared<Listener>(ioc, tcp::endpoint{address, port}, docRoot)->run();

    // Run the I/O service on the requested number of threads
    std::vector<std::thread> v;
    v.reserve(threads - 1);
    for (auto i = threads - 1; i > 0; --i) {
        v.emplace_back([&ioc] { ioc.run(); });
    }

    ioc.run();

    return EXIT_SUCCESS;
}
