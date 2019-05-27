//
// Created by Святослав Кряжев on 25.05.2019.
//

#ifndef MAIN_CREATEUSERCOMMAND_H
#define MAIN_CREATEUSERCOMMAND_H

#include "BaseCommand.h"
#include "user/User.h"


class CreateUserCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        _renderedPage = _renderer.signUp(_request);
    }
};


#endif //MAIN_CREATEUSERCOMMAND_H
