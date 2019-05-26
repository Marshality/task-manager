//
// Created by Marseille Gulaya on 2019-05-26.
//

#include "Listener.h"

Listener::Listener(boost::asio::io_context& ioc, tcp::endpoint endpoint,
                   std::shared_ptr<std::string const> const& _docRoot) :
        acceptor(ioc),
        socket(ioc),
        docRoot(_docRoot) {
    boost::system::error_code ec;

    acceptor.open(endpoint.protocol(), ec);
    if (ec) {
        std::cerr << "open: " << ec.message() << "\n";
        return;
    }

    acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
    if (ec) {
        std::cerr << "set_option: " << ec.message() << "\n";
        return;
    }

    acceptor.bind(endpoint, ec);
    if (ec) {
        std::cerr << "bind: " << ec.message() << "\n";
        return;
    }

    acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);
    if (ec) {
        std::cerr << "listen: " << ec.message() << "\n";
        return;
    }
}

void Listener::run() {
    if (!acceptor.is_open()) {
        return;
    }

    accept();
}

void Listener::accept() {
    acceptor.async_accept(socket, std::bind(
            &Listener::onAccept,
            shared_from_this(),
            std::placeholders::_1));
}

void Listener::onAccept(boost::system::error_code ec) {
    if (ec) {
        std::cerr << "accept: " << ec.message() << "\n";
    } else {
        std::make_shared<Session>(std::move(socket))->run();
    }

    accept();
}
