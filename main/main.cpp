#include <iostream>
#include "Storage.h"
#include "Set.h"
#include "task/Task.h"

int main() {
//    auto taskSet = Storage::getInstance().getMany<Task>("");
    auto taskSet = Task::getMany();
    taskSet->bypass([](Task& task) {
        std::cout << task.id() << " | "
                  << task.user_id() << " | "
                  << task.project_id() << " | "
                  << task.title() << " | "
                  << task.description() << " | "
                  << task.creation_date() << " | "
                  << task.deadline() << " | "
                  << std::endl;
    });

    return 0;
}