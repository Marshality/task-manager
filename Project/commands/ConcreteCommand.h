//
// Created by Marseille Gulaya on 2019-04-08.
//

#ifndef PROJECT_CONCRETECOMMAND_H
#define PROJECT_CONCRETECOMMAND_H

#include <iostream>
#include "ICommand.h"

class ConcreteCommand : public ICommand {
public:
    explicit ConcreteCommand(int arg) : value(arg) {}

    void execute() override;

private:
    int value;
};

#endif //PROJECT_CONCRETECOMMAND_H
