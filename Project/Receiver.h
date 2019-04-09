//
// Created by Marseille Gulaya on 2019-04-08.
//

#ifndef PROJECT_RECEIVER_H
#define PROJECT_RECEIVER_H

#include "commands/ConcreteCommand.h"
#include "Invoker.h"

class Receiver {
public:
    Receiver() = default;
    ~Receiver() = default;

    void test(int arg);

    void createProject();
    void deleteProject();

    void createTask();
    void deleteTask();

    void editProject();
    void editTask();

    void assignUser();

private:
    Invoker invoker;
};


#endif //PROJECT_RECEIVER_H
