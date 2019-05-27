//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "User.h"

#include "project/Project.h"
#include "task/Task.h"


// Direct fields

const char* User::id() const {
    return set->get(index, 0);
}

const char* User::username() const {
    return set->get(index, 1);
}

const char* User::password() const {
    return set->get(index, 2);
}

const char* User::name() const {
    return set->get(index, 3);
}

const char* User::surname() const {
    return set->get(index, 4);
}

// Relative fields

std::shared_ptr<Set<Project>> User::projects() {
    if (!projectsInstance) {
        projectsInstance = Project::getMany({
            {"owner_id", id()}
        });
    }

    return projectsInstance;
}

std::shared_ptr<Set<Task>> User::tasks() {
    if (!tasksInstance) {
        tasksInstance = Task::getMany({
            {"owner_id", id()}
        });
    }

    return tasksInstance;
}