//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_TASKCOMMAND_H
#define MAIN_TASKCOMMAND_H

#include "BaseCommand.h"
#include "task/Task.h"


class GetTaskCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto task = Task::getOne(_request.OPTIONS);

        _renderedPage = _renderer.taskPage(task);
    }
};

#endif //MAIN_TASKCOMMAND_H
