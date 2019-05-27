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

    }
};


#endif //MAIN_DELETETASKCOMMAND_H
