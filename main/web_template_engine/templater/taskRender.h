//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_TASK_H
#define MY_PROJECT_TASK_H

#include <mstch/mstch.hpp>
#include "../FileToStringConverter.h"
#include "task/Task.h"
#include "project/Project.h"
#include "user/User.h"


std::string renderTask(std::shared_ptr<Task> task) {
    FileToStringConverter path("../templates/");

    auto user = task->user();
    auto project = task->project();

    mstch::map context{
            {"title", std::string(task->title())},
            {"project", std::string(project->title())},
            {"description", std::string(task->description())},
            {"name", std::string(user->name())},
            {"surname", std::string(user->surname())},
            {"creation_date", std::string(task->creation_date())},
            {"deadline", std::string(task->deadline())}
    };

    return mstch::render(path("task.html"), context);
}

#endif //MY_PROJECT_TASK_H
