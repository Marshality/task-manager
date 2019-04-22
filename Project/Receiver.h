//
// Created by Marseille Gulaya on 2019-04-08.
//

#ifndef PROJECT_RECEIVER_H
#define PROJECT_RECEIVER_H

#include "commands/ConcreteCommand.h"
#include "commands/CreateProjectCommand.h"
#include "commands/CreateTaskCommand.h"
#include "commands/DeleteProjectCommand.h"
#include "commands/DeleteTaskCommand.h"
#include "commands/EditProjectCommand.h"
#include "commands/EditTaskCommand.h"

#include "Invoker.h"

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> DataPackage;

class Receiver {
public:
    Receiver() = default;
    ~Receiver() = default;

    void test(int arg);

    void createProject(DataPackage& data);
    void deleteProject(DataPackage& data);

    void createTask(DataPackage& data);
    void deleteTask(DataPackage& data);

    void editProject(DataPackage& data);
    void editTask(DataPackage& data);

private:
    Invoker invoker;
};


#endif //PROJECT_RECEIVER_H
