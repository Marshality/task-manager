//
// Created by Marseille Gulaya on 2019-05-26.
//

#include "HttpServer.h"

void HttpServer::run() {
    ioc.run();
}

HttpServer::HttpServer(boost::asio::ip::address address, unsigned short port, int t) :
        ioc(4),
        endpoint(address, port),
        countOfThreads(t) {
    listener = std::make_shared<Listener>(ioc, endpoint);
    std::cerr << "listen: " << address.to_string() << ":" << port << std::endl;
}

void HttpServer::serve() {
    listener->run();

    std::vector<std::thread> threads;
    threads.reserve(countOfThreads);

    for (int i = 0; i < countOfThreads; ++i) {
        threads.emplace_back(std::thread(std::bind(&HttpServer::run, this)));
    }

    for (auto& thread: threads) {
        thread.join();
    }
}
