//
// Created by Святослав Кряжев on 06.05.2019.
// featured by Gulaya Marseille
//

#ifndef MAIN_REQUEST_H
#define MAIN_REQUEST_H

#include "Types.h"

struct Request {
    enum RequestType {
        GET,
        POST
    } type;

    string_map options;
};

#endif //MAIN_REQUEST_H
