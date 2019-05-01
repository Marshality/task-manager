//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_IPROJECT_H
#define PROJECT_IPROJECT_H

#include <string>

class Project {
public:
    Project() = default;
    ~Project() = default;

    std::string title;
    std::string description;
};

#endif //PROJECT_IPROJECT_H
