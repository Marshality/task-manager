//
// Created by Юлия Плаксина on 2019-05-20.
//

#ifndef MY_PROJECT_TEST_H
#define MY_PROJECT_TEST_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"
#include "../TaskStruct.h"
#include <vector>

std::string test() {
    FileToStringConverter path("../templates/");

    std::vector<Project> projects {{}, {}, {}, {}, {}, {}};

    mstch::array arr;

    for (auto& project : projects) {
        arr.push_back(
                mstch::map{{"project", mstch::map{
                        {"title",       std::string(project.title())},
                        {"description", std::string(project.description())},
                        {"name",             std::string(project.name())},
                        {"surname",          std::string(project.surname())},
                        {"creation_date",    std::string(project.creation_date())}
                }}}
        );
    }

    mstch::map context {
            {"projects", arr}
    };

    return "ok";
}

#endif //MY_PROJECT_TEST_H
