#include "libraries.h"
#include "HttpServer.h"

int main(int argc, char* argv[]) {
//    if (argc != 4) {
//        std::cerr <<
//                  "Usage: server <address> <port> <threads>\n" <<
//                  "Example:\n" <<
//                  "    server 0.0.0.0 8080 1\n";
//        return EXIT_FAILURE;
//    }

//    auto const address = boost::asio::ip::make_address(argv[1]);
//    auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
//    auto const threads = std::max<int>(1, std::atoi(argv[3]));

    auto const address = boost::asio::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(std::atoi("8000"));
    auto const threads = std::max<int>(1, std::atoi("4"));

    HttpServer server(address, port, threads);

    server.serve();

    return EXIT_SUCCESS;
}
