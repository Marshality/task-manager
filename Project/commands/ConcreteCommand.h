//
// Created by Marseille Gulaya on 2019-04-08.
//

#ifndef PROJECT_CONCRETECOMMAND_H
#define PROJECT_CONCRETECOMMAND_H

#include <iostream>
#include "BaseCommand.h"

class ConcreteCommand : public BaseCommand {
public:
    explicit ConcreteCommand(int arg) : value(arg) {}

    void execute() override;

private:
    int value;
};

void ConcreteCommand::execute() {
    std::cout << value << std::endl;
}

#endif //PROJECT_CONCRETECOMMAND_H
