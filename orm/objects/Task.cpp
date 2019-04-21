//
// Created by Святослав Кряжев on 21.04.2019.
//

#include "Task.h"

static TaskManager* taskManagerInstance = nullptr;

TaskManager* Task::objects() {
    if (!taskManagerInstance) {
        taskManagerInstance = new TaskManager();
    }

    return taskManagerInstance;
}

void Task::save() {
    // query to database
}