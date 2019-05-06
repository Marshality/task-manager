//
// Created by Marseille Gulaya on 2019-04-22.
//

#ifndef PROJECT_IDISNOTFOUNDEXCEPTION_H
#define PROJECT_IDISNOTFOUNDEXCEPTION_H

#include <exception>

class IdIsNotFoundException : public std::exception {
public:
    const char* what() const noexcept override { return "Id is not found."; }
};

#endif //PROJECT_IDISNOTFOUNDEXCEPTION_H
