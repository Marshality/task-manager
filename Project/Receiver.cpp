//
// Created by Marseille Gulaya on 2019-04-08.
//

#include "Receiver.h"
#include "Task.h"

void Receiver::test(int arg) {
    invoker.setCommand(new ConcreteCommand(arg));
    invoker.execute();
}

void Receiver::createTask(DataPackage& data) {
    invoker.setCommand(new CreateTaskCommand(data));
    invoker.execute();
}

void Receiver::createProject(DataPackage& data) {
    invoker.setCommand(new CreateProjectCommand(data));
    invoker.execute();
}

void Receiver::deleteProject(DataPackage& data) {
    invoker.setCommand(new DeleteProjectCommand(data));
    invoker.execute();
}

void Receiver::deleteTask(DataPackage& data) {
    invoker.setCommand(new DeleteTaskCommand(data));
    invoker.execute();
}

void Receiver::editTask(DataPackage& data) {
    invoker.setCommand(new EditTaskCommand(data));
    invoker.execute();
}

void Receiver::editProject(DataPackage& data) {
    invoker.setCommand(new EditProjectCommand(data));
    invoker.execute();
}
