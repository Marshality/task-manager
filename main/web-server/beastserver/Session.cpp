//
// Created by Marseille Gulaya on 2019-05-26.
//

#include "Session.h"

Session::Session(tcp::socket _socket, std::shared_ptr<std::string const> const& _docRoot) :
        socket(std::move(_socket)),
        strand(socket.get_executor()),
        docRoot(_docRoot),
        lambda(*this) {
}

void Session::read() {
    req = {};

    http::async_read(socket, buffer, req, boost::asio::bind_executor(strand, std::bind(
            &Session::onRead,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2)));
}

void Session::onRead(boost::system::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec == http::error::end_of_stream) {
        return close();
    }

    if (ec) {
        std::cerr << "read: " << ec.message() << "\n";
        return;
    }

    handleRequest(*docRoot, std::move(req), lambda);
}

void Session::onWrite(boost::system::error_code ec, std::size_t bytes_transferred, bool close) {
    boost::ignore_unused(bytes_transferred);

    if (ec) {
        std::cerr << "write: " << ec.message() << "\n";
        return;
    }

    if (close) {
        this->close();
        return;
    }

    res = nullptr;

    read();
}

void Session::close() {
    boost::system::error_code ec;
    socket.shutdown(tcp::socket::shutdown_send, ec);
}

void Session::run() {
    read();
}
