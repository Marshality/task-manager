//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef MAIN_LOGIC_REQUEST_H
#define MAIN_LOGIC_REQUEST_H

#include <string>
#include <unordered_map>

using map = std::unordered_map<std::string, std::string>;

enum RequestType {
    GET,
    POST
};

struct Request {
    RequestType type;
    map options;
};

#endif //MAIN_LOGIC_REQUEST_H
