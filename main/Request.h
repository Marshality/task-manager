//
// Created by Святослав Кряжев on 06.05.2019.
// featured by Gulaya Marseille
//

#ifndef MAIN_REQUEST_H
#define MAIN_REQUEST_H

#include <string>
#include <unordered_map>

using map = std::unordered_map<std::string, std::string>;

struct Request {
    enum RequestType {
        GET,
        POST
    } type;

    map options;
};

#endif //MAIN_REQUEST_H
