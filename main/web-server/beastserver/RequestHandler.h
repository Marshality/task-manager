//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_REQUESTHANDLER_H
#define MAIN_REQUESTHANDLER_H

#include "libraries.h"
#include "../../Controller.h"
#include "../../Request.h"

template <class Send>
class RequestHandler {
public:
    explicit RequestHandler(Send&& _send) : send(_send) {}

    ~RequestHandler() = default;

    template <class Body, class Allocator>
    void handle(http::request<Body, http::basic_fields<Allocator>>&& req);

private:
    Send send;
};

template <class Send>
template <class Body, class Allocator>
void RequestHandler<Send>::handle(http::request<Body, boost::beast::http::basic_fields<Allocator>>&& req) {
    auto const badRequest = [&req](boost::beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = why.to_string();
        res.prepare_payload();
        return res;
    };

    auto const notFound = [&req](boost::beast::string_view target) {
        http::response<http::string_body> res{http::status::not_found, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "The resource '" + target.to_string() + "' was not found.";
        res.prepare_payload();
        return res;
    };

    // Make sure we can handle the method
    if (req.method() != http::verb::get && req.method() != http::verb::head) {
        return send(badRequest("Unknown HTTP-method"));
    }

    // Request path must be absolute and not contain "..".
    if (req.target().empty() || req.target()[0] != '/' ||
        req.target().find("..") != boost::beast::string_view::npos) {
        return send(badRequest("Illegal request-target"));
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
        return send(notFound(req.target()));
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


#endif //MAIN_REQUESTHANDLER_H
