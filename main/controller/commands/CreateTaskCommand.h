//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_CREATETASKCOMMAND_H
#define MAIN_CREATETASKCOMMAND_H

#include "BaseCommand.h"
#include "task/Task.h"


class CreateTaskCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto user = authenticate();
        auto users = User::getMany({});

        _renderedPage = _renderer.addTask(_request, users);
    }
};


#endif //MAIN_CREATETASKCOMMAND_H
