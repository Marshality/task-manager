//
// Created by Святослав Кряжев on 06.05.2019.
//

#include "Controller.h"

#include "commands.h"


std::string Controller::createTask(Request& request) {
    CreateProjectCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::createProject(Request& request) {
    CreateProjectCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::deleteProject(Request& request) {
    DeleteProjectCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::deleteTask(Request& request) {
    DeleteTaskCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::editTask(Request& request) {
    EditTaskCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::editProject(Request& request) {
    EditProjectCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::task(Request& request) {
    GetTaskCommand cmd(renderer, request);
    return execute(cmd);
}

std::string Controller::project(Request& request) {
    GetProjectCommand cmd(renderer, request);
    return execute(cmd);
}