//
// Created by Святослав Кряжев on 06.05.2019.
//

#include "Controller.h"
#include "CreateProjectCommand.h"
#include "CreateProjectCommand.h"
#include "DeleteProjectCommand.h"
#include "DeleteTaskCommand.h"
#include "EditTaskCommand.h"
#include "EditProjectCommand.h"

void Controller::createTask(Request& request) {
    CreateProjectCommand cmd(request);
    execute(cmd);
}

void Controller::createProject(Request& request) {
    CreateProjectCommand cmd(request);
    execute(cmd);
}

void Controller::deleteProject(Request& request) {
    DeleteProjectCommand cmd(request);
    execute(cmd);
}

void Controller::deleteTask(Request& request) {
    DeleteTaskCommand cmd(request);
    execute(cmd);
}

void Controller::editTask(Request& request) {
    EditTaskCommand cmd(request);
    execute(cmd);
}

void Controller::editProject(Request& request) {
    EditProjectCommand cmd(request);
    execute(cmd);
}
