//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_USERNAMEMISMATCHEXCEPTION_H
#define MAIN_USERNAMEMISMATCHEXCEPTION_H

#include <exception>


class UsernameMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: username from URL & username from POST don't match";
    }
};


#endif //MAIN_USERNAMEMISMATCHEXCEPTION_H
