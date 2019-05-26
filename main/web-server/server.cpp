#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>


#include <boost/asio.hpp>
#include <functional>
#include <thread>

#include <boost/bind.hpp>

#include "asyncserver.h"


#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    HttpServer server(5000);

    server.serve();
    return 0;
}