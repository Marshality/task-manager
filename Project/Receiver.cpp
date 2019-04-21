//
// Created by Marseille Gulaya on 2019-04-08.
//

#include "Receiver.h"
#include "Task.h"

void Receiver::test(int arg) {
    invoker.setCommand(new ConcreteCommand(arg));
    invoker.execute();
}

void Receiver::createTask(std::unordered_map<std::string, std::string>& data) {
    invoker.setCommand(new CreateTaskCommand(data));
    invoker.execute();
}

void Receiver::createProject(std::unordered_map<std::string, std::string>& data) {
    invoker.setCommand(new CreateProjectCommand(data));
    invoker.execute();
}

void Receiver::deleteProject(std::string& id) {
    invoker.setCommand(new DeleteProjectCommand(id));
    invoker.execute();
}

void Receiver::deleteTask(std::string& id) {
    invoker.setCommand(new DeleteTaskCommand(id));
    invoker.execute();
}

void Receiver::editTask(std::unordered_map<std::string, std::string>& data) {
    invoker.setCommand(new EditTaskCommand(data));
    invoker.execute();
}

void Receiver::editProject(std::unordered_map<std::string, std::string>& data) {
    invoker.setCommand(new EditProjectCommand(data));
    invoker.execute();
}
