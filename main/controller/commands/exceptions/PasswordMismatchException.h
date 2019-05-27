//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_PASSWORDMISMATCHEXCEPTION_H
#define MAIN_PASSWORDMISMATCHEXCEPTION_H

#include <exception>


class PasswordMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: passwords mismatch";
    }
};

#endif //MAIN_PASSWORDMISMATCHEXCEPTION_H
