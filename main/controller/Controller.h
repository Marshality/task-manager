//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <string>
#include <iostream>
#include "Request.h"
#include "commands/BaseCommand.h"


class Controller {
public:
    std::string index(Request& request);

    std::string createProject(Request& request);
    std::string deleteProject(Request& request);

    std::string createTask(Request& request);
    std::string deleteTask(Request& request);

    std::string signUp(Request& request);
    std::string signIn(Request& request);
    std::string deleteAccount(Request& request);

    std::string task(Request& request);
    std::string project(Request& request);

    std::string projectList(Request& request);

private:
    Renderer _renderer;

    std::string execute(BaseCommand& cmd) {
        try {
            cmd.execute();
            return cmd.getPage();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            return "Error page";
        }
    }
};


#endif //MAIN_CONTROLLER_H
