//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "User.h"


// Direct fields

const char* User::id() const {

}

const char* User::name() const {

}

const char* User::surname() const {

}

const char* User::birth_date() const {

}

const char* User::avatar() const {

}

// Relative fields

std::shared_ptr<ProjectSet> User::projects() {
    if (!projectsInstance) {

    }

    return projectsInstance;
}

std::shared_ptr<TaskSet> User::tasks() {
    if (!tasksInstance) {

    }

    return tasksInstance;
}