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

class Receiver {
public:
    Receiver() = default;
    ~Receiver() = default;

    void test(int arg);

    void createProject(std::unordered_map<std::string, std::string>& data);
    void deleteProject(std::string& id);

    void createTask(std::unordered_map<std::string, std::string>& data);
    void deleteTask(std::string& id);

    void editProject(std::unordered_map<std::string, std::string>& data);
    void editTask(std::unordered_map<std::string, std::string>& data);

private:
    Invoker invoker;
};


#endif //PROJECT_RECEIVER_H
