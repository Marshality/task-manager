//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_SESSION_H
#define MAIN_SESSION_H

#include "libraries.h"
#include "RequestHandler.h"

class Session : public std::enable_shared_from_this<Session> {
    struct SendLambda {
        Session& self;

        explicit SendLambda(Session& _self) : self(_self) {}

        template <bool isRequest, class Body, class Fields>
        void operator()(http::message<isRequest, Body, Fields>&& msg) const {
            // The lifetime of the message has to extend
            // for the duration of the async operation so
            // we use a shared_ptr to manage it.
            auto sp = std::make_shared<http::message<isRequest, Body, Fields>>(std::move(msg));

            // Store a type-erased version of the shared
            // pointer in the class to keep it alive.
            self.res = sp;

            http::async_write(self.socket, *sp, boost::asio::bind_executor(self.strand, std::bind(
                    &Session::onWrite,
                    self.shared_from_this(),
                    std::placeholders::_1,
                    std::placeholders::_2,
                    sp->need_eof())));
        }
    };

    tcp::socket socket;
    boost::asio::strand<boost::asio::io_context::executor_type> strand;
    boost::beast::flat_buffer buffer;
    http::request<http::string_body> req;
    std::shared_ptr<void> res;
    RequestHandler<SendLambda> handler;

public:
    explicit Session(tcp::socket _socket);

    void run();

    void read();
    void onRead(boost::system::error_code ec, std::size_t bytes_transferred);

    void onWrite(boost::system::error_code ec, std::size_t bytes_transferred, bool close);

    void close();
};

#endif //MAIN_SESSION_H
