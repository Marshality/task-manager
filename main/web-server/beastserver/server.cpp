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
