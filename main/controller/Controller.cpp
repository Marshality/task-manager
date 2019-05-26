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
    CreateProjectCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::deleteTask(Request& request) {
    DeleteTaskCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createProject(Request& request) {
    CreateProjectCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::deleteProject(Request& request) {
    DeleteProjectCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::createUser(Request& request) {
    CreateUserCommand cmd(_renderer, request);
    return execute(cmd);
}

std::string Controller::deleteUser(Request& request) {

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

