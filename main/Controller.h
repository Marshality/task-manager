//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <string>
#include <iostream>
#include "Request.h"
#include "BaseCommand.h"


class Controller {
public:
    std::string createProject(Request& request);
    std::string deleteProject(Request& request);

    std::string createTask(Request& request);
    std::string deleteTask(Request& request);

    std::string editProject(Request& request);
    std::string editTask(Request& request);

    std::string task(Request& request);

private:
    Renderer renderer;

    std::string execute(BaseCommand& cmd) {
        try {
            cmd.execute();
            return cmd.getPage();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            return "ERROR";
        }
    }
};


#endif //MAIN_CONTROLLER_H