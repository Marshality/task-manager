//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_HEADER_H
#define MY_PROJECT_HEADER_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"

std::string base(std::string body, std::string pageTitle) {

    FileToStringConverter path("../templates/");

    mstch::map base{
            {"pageTitle", pageTitle},
            {"body", body}
    };

    return mstch::render(path("base.html"), base);
}

#endif //MY_PROJECT_HEADER_H
