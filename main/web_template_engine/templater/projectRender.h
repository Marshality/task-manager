//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_TASKS_H
#define MY_PROJECT_TASKS_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"
#include "../TaskStruct.h"
#include <vector>

std::string project() {
    FileToStringConverter path("../templates/");

    struct Project project;
    struct Task user;

    std::vector<Task> tasks {{}, {}, {}, {}};

    mstch::array arr;

    for (auto& task : tasks) {
        arr.push_back(
                mstch::map{{"task", mstch::map{
                        {"title",       std::string(task.title())},
                        {"description", std::string(task.description())},
                        {"name",             std::string(user.title())},
                        {"surname",          std::string(user.title())},
                        {"deadline",    std::string(task.deadline())}
                }}}
        );
    }
    mstch::map context{
            {"title", std::string(project.title())},
            {"description", std::string(project.description())},
            {"name", std::string(user.title())},
            {"surname", std::string(user.title())},
            {"creation_date", std::string(project.creation_date())},
            {"tasks", arr}
    };

    return mstch::render(path("project.html"), context);
}

#endif //MY_PROJECT_TASKS_H
