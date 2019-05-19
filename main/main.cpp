#include <iostream>
#include "Storage.h"
#include "task/TaskSet.h"

int main() {
    auto set = Storage::getInstance().query("SELECT * FROM tasks;");

    TaskSet taskSet(set);
    taskSet.bypass([](Task& task) {
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