//
// Created by Marseille Gulaya on 2019-04-09.
//

#ifndef PROJECT_IUSER_H
#define PROJECT_IUSER_H

#include <string>

class User {
public:
    User() = default;
    ~User() = default;

private:
    int id;

    std::string firstName;
    std::string secondName;

    std::string role;
};

#endif //PROJECT_IUSER_H
