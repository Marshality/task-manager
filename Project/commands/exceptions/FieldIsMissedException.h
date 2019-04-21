//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_FIELDISMISSEDEXCEPTION_H
#define PROJECT_FIELDISMISSEDEXCEPTION_H

#include <exception>

class FieldIsMissedException : public std::exception {
public:
    const char* what() const noexcept override { return "Field is missed."; }
};

#endif //PROJECT_FIELDISMISSEDEXCEPTION_H
