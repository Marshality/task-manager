#include <iostream>
//#include "task/Task.h"
//#include "project/Project.h"
//#include "user/User.h"

#include "Controller.h"
#include "web_template_engine/Renderer.h"

int main() {
    Controller controller;
    Request request;
    std::string string;
    controller.task(request, string);

    Renderer renderer;

    auto task = Task::getOne({{}});
//    auto project = Project::getOne({{}});
    std::cout << renderer.TaskPage(task);



return 0;
}