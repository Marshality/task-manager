//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_HTTPSERVER_H
#define MAIN_HTTPSERVER_H

#include "libraries.h"
#include "Listener.h"

class HttpServer {
public:
    HttpServer(boost::asio::ip::address address, unsigned short port, int t);

    void serve();

    void run();

private:
    boost::asio::io_context ioc;
    tcp::endpoint endpoint;
    std::shared_ptr<Listener> listener;
    int countOfThreads;
};

#endif //MAIN_HTTPSERVER_H
