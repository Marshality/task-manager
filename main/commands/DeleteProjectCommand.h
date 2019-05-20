//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_DELETEPROJECTCOMMAND_H
#define MAIN_DELETEPROJECTCOMMAND_H

#include "BaseCommand.h"


class DeleteProjectCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() const override {

    }
};


#endif //MAIN_DELETEPROJECTCOMMAND_H
