//
// Created by Святослав Кряжев on 06.05.2019.
// featured by Gulaya Marseille
//

#ifndef MAIN_REQUEST_H
#define MAIN_REQUEST_H

#include "Types.h"

struct Request {
    string_map GET;
    string_map POST;

    string_map OPTIONS;
};

#endif //MAIN_REQUEST_H
