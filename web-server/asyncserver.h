//
// Created by Marseille Gulaya on 2019-05-19.
//

#ifndef BOOST_ASYNCSERVER_H
#define BOOST_ASYNCSERVER_H

#include <boost/asio.hpp>
#include <iostream>
#include "getter.h"
#include <boost/beast/http.hpp>

#define COUNT_OF_THREADS 4
#define BUFFER_SIZE 1024

using namespace boost;
using namespace boost::asio;
using namespace boost::beast;

class Client : public std::enable_shared_from_this<Client> {
private:
    ip::tcp::socket socket;
    char buffer[BUFFER_SIZE];
//    http::request<http::string_body> request;
//    ::strand<io_context::executor_type> strand;

    void onRead(const system::error_code& error, std::size_t bytes) {
        if (error == asio::error::eof) {
            std::cerr << "-: " << socket.remote_endpoint().address().to_string() << std::endl;
        }

        if (error) {
            return;
        }


//        std::istringstream request(buffer, bytes);
//        std::string test;
//
//        std::getline(request, test, '\n');
//
//        std::map<std::string, std::string> params = getParams(test);
//
//        std::cout << params["param"].data() << std::endl;
//
        std::stringstream responseBody, response;

        responseBody << "<title>Test C++ HTTP Server</title>\n"
                     << "<h1>Test page</h1>\n"
                     << "<p>This is body of the test page...</p>\n"
                     << "<h2>Request headers</h2>\n"
                     << "<pre>" << buffer << "</pre>\n"
                     << "<em><small>Test C++ Http Server</small></em>\n";


        response << "HTTP/1.1 200 OK\r\n"
                 << "Version: HTTP/1.1\r\n"
                 << "Content-Type: text/html; charset=utf-8\r\n"
                 << "Content-Length: " << responseBody.str().length()
                 << "\r\n\r\n"
                 << responseBody.str();

        socket.async_write_some(asio::buffer(response.str()),
                                [self = shared_from_this()](const boost::system::error_code& e,
                                                            std::size_t bytes) -> void {
//                                    self->read();
                                });
    }

public:
    explicit Client(io_service& service) : socket(service) {
//        this->strand = ::strand<io_context::executor_type>(socket.get_executor());
    }

    ~Client() = default;

    ip::tcp::socket& getSocket() {
        return socket;
    }

    void read() {
//        request = {};

//        http::async_read(socket, buffer, request,
//                         boost::asio::bind_executor(
//                                 strand,
//                                 std::bind(
//                                         &Client::onRead,
//                                         shared_from_this(),
//                                         std::placeholders::_1,
//                                         std::placeholders::_2)));



        socket.async_read_some(asio::buffer(buffer),
                               std::bind(&Client::onRead, shared_from_this(), std::placeholders::_1,
                                         std::placeholders::_2));
    }
};

class Listener : public std::enable_shared_from_this<Listener> {
private:
    io_service* service;
    ip::tcp::acceptor acceptor;

    void accept() {
        std::shared_ptr<Client> client(new Client(*service));
        acceptor.async_accept(client->getSocket(),
                              std::bind(&Listener::onAccept, shared_from_this(), client, std::placeholders::_1));
    }

    void onAccept(std::shared_ptr<Client>& client, const system::error_code& errorCode) {
        if (errorCode) {
            std::cerr << "disconnect" << std::endl;
            return;
        }

        std::cerr << "+: " << client->getSocket().remote_endpoint().address().to_string().c_str() << std::endl;

        client->read();

        accept();
    }

public:
    explicit Listener(io_service* _service, ip::tcp::endpoint* _endpoint) :
            service(_service),
            acceptor(*_service, *_endpoint) {}

    void listen() {
        accept();
    }

    ~Listener() = default;
};

class HttpServer {
private:
    io_service service;
    ip::tcp::endpoint endpoint;
    std::shared_ptr<Listener> listener;

public:
    explicit HttpServer(unsigned short port) : endpoint(ip::tcp::v4(), port) {
        listener = std::make_shared<Listener>(&service, &endpoint);
        std::cerr << "listen: " << port << std::endl;
    }

    ~HttpServer() = default;

    void serve() {
        listener->listen();

        std::vector<std::thread> threads;
        threads.reserve(COUNT_OF_THREADS);

        for (int i = 0; i < COUNT_OF_THREADS; ++i) {
            threads.emplace_back(std::thread(std::bind(&HttpServer::run, this)));
        }

        for (auto& thread: threads) {
            thread.join();
        }
    }

    void run() {
        service.run();
    }
};


#endif //BOOST_ASYNCSERVER_H
