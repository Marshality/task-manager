//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_INVOKER_H
#define PROJECT_INVOKER_H

#include "commands/ICommand.h"

class Invoker {
public:
    Invoker() = default;

    ~Invoker() {
        delete command;
    };

    void setCommand(ICommand* command) {
        this->command = command;
    }

    void execute() {
        this->command->execute();
    }

private:
    ICommand* command;
};

#endif //PROJECT_INVOKER_H
