//
// Created by Святослав Кряжев on 19.05.2019.
//

#include "Task.h"

#include "project/Project.h"
#include "user/User.h"


// Direct fields

const char* Task::id() const {
    return set->get(index, 0);
}

const char* Task::user_id() const {
    return set->get(index, 1);
}

const char* Task::project_id() const {
    return set->get(index, 2);
}

const char* Task::title() const {
    return set->get(index, 3);
}

const char* Task::description() const {
    return set->get(index, 4);
}

const char* Task::creation_date() const {
    return set->get(index, 5);
}

const char* Task::deadline() const {
    return set->get(index, 6);
}

// Relative fields

std::shared_ptr<User> Task::user() {
    if (!userInstance) {
        userInstance = User::getOne({
            {"id", user_id()}
        });
    }

    return userInstance;
}

std::shared_ptr<Project> Task::project() {
    if (!projectInstance) {
        projectInstance = Project::getOne({
            {"id", project_id()}
        });
    }

    return projectInstance;
}