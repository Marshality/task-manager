//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_DELETETASKCOMMAND_H
#define MAIN_DELETETASKCOMMAND_H

#include "BaseCommand.h"


class CreateTaskCommandSuccess : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto user = authenticate();

        Task::create(_request.POST);

        _renderedPage = _renderer.addTaskSuccess(_request);
    }
};


#endif //MAIN_DELETETASKCOMMAND_H
