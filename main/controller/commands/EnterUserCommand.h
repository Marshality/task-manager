//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_ENTERUSERCOMMAND_H
#define MAIN_ENTERUSERCOMMAND_H

#include "BaseCommand.h"


class EnterUserCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        _renderedPage = _renderer.signIn(_request);
    }
};


#endif //MAIN_ENTERUSERCOMMAND_H
