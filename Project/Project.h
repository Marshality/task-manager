//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_IPROJECT_H
#define PROJECT_IPROJECT_H

#include <string>
#include <vector>

#include "Task.h"
#include "User.h"

class Project {
public:
    Project() = default;
    ~Project() = default;

private:
    int id;

    std::string title;
    std::string description;

    std::vector<Task> tasks;
    std::vector<User> users;
};

#endif //PROJECT_IPROJECT_H
