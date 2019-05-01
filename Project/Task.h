//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_ITASK_H
#define PROJECT_ITASK_H

#include <string>

class Task {
public:
    Task() = default;
    ~Task() = default;

    std::string title;
    std::string description;
    std::string assignee;
};

#endif //PROJECT_ITASK_H
