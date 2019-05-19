//
// Created by Святослав Кряжев on 19.05.2019.
//

#include "Project.h"


// Direct fields

const char* Project::id() const {
    return set->get(index, 0);
}

const char* Project::owner_id() const {
    return set->get(index, 1);
}

const char* Project::title() const {
    return set->get(index, 2);;
}

const char* Project::description() const {
    return set->get(index, 3);;
}

const char* Project::creation_date() const {
    return set->get(index, 4);;
}

// Relative fields

std::shared_ptr<User> Project::owner() {
    if (!ownerInstance) {

    }

    return ownerInstance;
}

std::shared_ptr<TaskSet> Project::tasks() {
    if (!tasksInstance) {

    }

    return tasksInstance;
}