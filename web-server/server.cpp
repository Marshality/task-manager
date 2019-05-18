#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>

#define BUFFER_SIZE 1024

int receiveAll(int sockfd, void *buf, size_t len, int flags) { // С ней почему-то не работает...
    int total = 0;
    ssize_t bytesRead;

    while (true) {
        bytesRead = recv(sockfd, buf, len, flags);
        if (bytesRead <= 0) break;
        total += bytesRead;
    }

    return total;
}

int main() {
    ssize_t result = 0;
    int listener = 0;
    struct sockaddr_in address;

    listener = socket(AF_INET, SOCK_STREAM, 0);

    if (listener < 0) {
        std::cerr << "socket failed" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(8000);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    result = bind(listener, (struct sockaddr*) &address, sizeof(address));

    if (result < 0) {
        std::cerr << "bind failed" << std::endl;
        return -1;
    }

    listen(listener, 1);

    char buf[BUFFER_SIZE];
    int worker;

    while (true) {
        worker = accept(listener, nullptr, nullptr);

        if (worker < 0) {
            std::cerr << "accept failed" << std::endl;
            close(listener);
            return -1;
        }

        result = recv(worker, buf, BUFFER_SIZE, 0);

        std::stringstream response;
        std::stringstream response_body;

        if (result < 0) {
            std::cerr << "receive failed" << std::endl;
        } else if (result == 0) {
            std::cerr << "connection closed" << std::endl;
        } else {
            // Мы знаем фактический размер полученных данных, поэтому ставим метку конца строки
            buf[result] = '\0';

            std::cout << result << std::endl;

            // Данные успешно получены
            // формируем тело ответа (HTML)
            response_body << "<title>Test C++ HTTP Server</title>\n"
                          << "<h1>Test page</h1>\n"
                          << "<p>This is body of the test page...</p>\n"
                          << "<h2>Request headers</h2>\n"
                          << "<pre>" << buf << "</pre>\n"
                          << "<em><small>Test C++ Http Server</small></em>\n";

            // Формируем весь ответ вместе с заголовками
            response << "HTTP/1.1 200 OK\r\n"
                     << "Version: HTTP/1.1\r\n"
                     << "Content-Type: text/html; charset=utf-8\r\n"
                     << "Content-Length: " << response_body.str().length()
                     << "\r\n\r\n"
                     << response_body.str();

            // Отправляем ответ клиенту с помощью функции send
            result = send(worker, response.str().c_str(), response.str().length(), 0);

            if (result < 0) {
                // произошла ошибка при отправле данных
                std::cerr << "send failed: " << std::endl;
            }
            // Закрываем соединение к клиентом
            close(worker);
        }
    }
}