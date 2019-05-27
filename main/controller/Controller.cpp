//
// Created by Святослав Кряжев on 06.05.2019.
//

#include "Controller.h"

#include "commands.h"


std::string Controller::index(Request& request) {
    IndexCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createTask(Request& request) {
    CreateTaskCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createTaskSuccess(Request& request) {
    CreateTaskCommandSuccess cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createProject(Request& request) {
    CreateProjectCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createProjectSuccess(Request& request) {
    CreateProjectSuccessCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createUser(Request& request) {
    CreateUserCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::enterUser(Request& request) {
    EnterUserCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::userSuccess(Request& request) {
    DeleteUserCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::task(Request& request) {
    GetTaskCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::project(Request& request) {
    GetProjectCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::projectList(Request& request) {
    GetProjectListCommand cmd(_renderer, request);
    return execute(cmd);
}

