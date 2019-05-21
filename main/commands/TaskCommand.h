//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_TASKCOMMAND_H
#define MAIN_TASKCOMMAND_H

#include <iostream>
#include "BaseCommand.h"
#include "task/Task.h"
#include "user/User.h"
#include "project/Project.h"
#include "web_template_engine/Renderer.h"


class TaskCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() const override {
        auto task = Task::getOne({{"id", "1"}});

        Renderer renderer;
        std::cout << renderer.TaskPage(task) << std::endl;
    }
};

#endif //MAIN_TASKCOMMAND_H
