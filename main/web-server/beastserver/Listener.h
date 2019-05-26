//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_LISTENER_H
#define MAIN_LISTENER_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include "Session.h"

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

void fail(boost::system::error_code ec, char const* what) {
    std::cerr << what << ": " << ec.message() << "\n";
}

class Listener : public std::enable_shared_from_this<Listener> {
    tcp::acceptor acceptor;
    tcp::socket socket;
    std::shared_ptr<std::string const> docRoot;

public:
    Listener(boost::asio::io_context& ioc, tcp::endpoint endpoint, std::shared_ptr<std::string const> const& _docRoot);

    void run();
    void accept();
    void onAccept(boost::system::error_code ec);
};


#endif //MAIN_LISTENER_H
