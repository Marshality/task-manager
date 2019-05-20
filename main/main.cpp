#include <iostream>
//#include "task/Task.h"
//#include "project/Project.h"
//#include "user/User.h"

#include "Controller.h"


int main() {
//    auto taskSet = Task::getMany({});
//    taskSet->bypass([](Task& task) {
//        std::cout << task.id() << " | "
//                  << task.user_id() << " | "
//                  << task.project_id() << " | "
//                  << task.title() << " | "
//                  << task.description() << " | "
//                  << task.creation_date() << " | "
//                  << task.deadline() << " | "
//                  << std::endl;
//
//        auto project = task.project();
//        std::cout << project->id() << " | "
//                  << project->owner_id() << " | "
//                  << project->title() << " | "
//                  << project->description() << " | "
//                  << project->creation_date() << " | "
//                  << std::endl;
//
//        auto user = task.user();
//        std::cout << user->id() << " | "
//                  << user->name() << " | "
//                  << user->surname() << " | "
//                  << user->birth_date() << " | "
//                  << user->avatar() << " | "
//                  << std::endl;
//    });

    Controller controller;
    Request request;
    std::string string;
    controller.task(request, string);

    return 0;
}