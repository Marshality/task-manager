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
    void createProject(Request& request);
    void deleteProject(Request& request);

    void createTask(Request& request);
    void deleteTask(Request& request);

    void editProject(Request& request);
    void editTask(Request& request);

private:
    void execute(BaseCommand& cmd) {
        try {
            cmd.execute();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
};


#endif //MAIN_CONTROLLER_H
