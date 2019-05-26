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
        Task::create(_request.OPTIONS);
    }
};


#endif //MAIN_CREATETASKCOMMAND_H
