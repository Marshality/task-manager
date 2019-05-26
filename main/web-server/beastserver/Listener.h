//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_LISTENER_H
#define MAIN_LISTENER_H

#include "libraries.h"

#include "Session.h"

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

class Listener : public std::enable_shared_from_this<Listener> {
    tcp::acceptor acceptor;
    tcp::socket socket;

public:
    Listener(boost::asio::io_context& ioc, tcp::endpoint endpoint);

    void run();
    void accept();
    void onAccept(boost::system::error_code ec);
};


#endif //MAIN_LISTENER_H
