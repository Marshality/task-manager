//
// Created by Marseille Gulaya on 2019-04-08.
//

#include "Controller.h"

void Controller::createTask(DataPackage& data) {
    invoker.setCommand(new CreateTaskCommand(data));
    invoker.execute();
}

void Controller::createProject(DataPackage& data) {
    invoker.setCommand(new CreateProjectCommand(data));
    invoker.execute();
}

void Controller::deleteProject(DataPackage& data) {
    invoker.setCommand(new DeleteProjectCommand(data));
    invoker.execute();
}

void Controller::deleteTask(DataPackage& data) {
    invoker.setCommand(new DeleteTaskCommand(data));
    invoker.execute();
}

void Controller::editTask(DataPackage& data) {
    invoker.setCommand(new EditTaskCommand(data));
    invoker.execute();
}

void Controller::editProject(DataPackage& data) {
    invoker.setCommand(new EditProjectCommand(data));
    invoker.execute();
}
