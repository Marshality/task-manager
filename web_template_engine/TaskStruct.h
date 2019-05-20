//
// Created by Юлия Плаксина on 2019-05-19.
//

#ifndef MY_PROJECT_TASKSTRUCT_H
#define MY_PROJECT_TASKSTRUCT_H

#include <vector>

struct Task {

    const char* id() const {
        return "id";
    }

    const char* user_id() const {
        return "user_id";
    }

    const char* project_id() const {
        return "project_id";
    }

    const char* title() const {
        return "title";
    }

    const char* description() const {
        return "a long long (or not so long) description for a single task. Think about. a long long (or not so long) description for a single task. Think about";
    }

    const char* creation_date() const {
        return "creation_date";
    }

    const char* deadline() const {
        return "deadline";
    }
};

struct Project {

    const char* id() const {
        return "id";
    }

    const char* title() const {
        return "title";
    }

    const char* description() const {
        return "a long long (or not so long) description for a single task. Think about it";
    }

    const char* creation_date() const {
        return "creation_date";
    }

    const char* name() const {
        return "name";
    }

    const char* surname() const {
        return "surname";
    }

    std::vector<struct Task> tasks;

};
#endif //MY_PROJECT_TASKSTRUCT_H
