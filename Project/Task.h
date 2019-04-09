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

private:
    int id;

    std::string title;
    std::string description;

    int startTime, endTime;

    std::string assignee;
    int assigneeId;
};

#endif //PROJECT_ITASK_H
