//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_MAIN_H
#define MY_PROJECT_MAIN_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"
std::string mainPage() {
    FileToStringConverter path("../templates/");

    return path("mainPage.html");
}
#endif //MY_PROJECT_MAIN_H
