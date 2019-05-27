#include "libraries.h"
#include "HttpServer.h"

int main(int argc, char* argv[]) {
    auto const address = boost::asio::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(std::atoi("8000"));
    auto const threads = std::max<int>(1, std::atoi("4"));

    HttpServer server(address, port, threads);

    server.serve();

    return EXIT_SUCCESS;
}
