//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_TASK_H
#define MY_PROJECT_TASK_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"
#include "../TaskStruct.h"


std::string task() {
    FileToStringConverter path("../templates/");

    struct Task task;
    struct Task project;
    struct Task user;

    mstch::map context{
            {"title", std::string(task.title())},
            {"project", std::string(project.title())},
            {"description", std::string(task.description())},
            {"name", std::string(user.title())},
            {"surname", std::string(user.title())},
            {"creation_date", std::string(task.creation_date())},
            {"deadline", mstch::map{
                {"day", 27},
                {"month", std::string{"мая"}},
                {"year", std::string{"2019"}},
                {"time", std::string{"12:00"}}}
            }
    };
    return mstch::render(path("task.html"), context);
}

#endif //MY_PROJECT_TASK_H
