//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_INVOKER_H
#define PROJECT_INVOKER_H

#include "commands/BaseCommand.h"
#include <exception>

class Invoker {
public:
    Invoker() = default;

    ~Invoker() {
        if (command) {
            delete command;
        }
    };

    void setCommand(BaseCommand* command) {
        this->command = command;
    }

    void execute() {
        try {
            this->command->execute();
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        delete command;
    }

private:
    BaseCommand* command;
};

#endif //PROJECT_INVOKER_H
