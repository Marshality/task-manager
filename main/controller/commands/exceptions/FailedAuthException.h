//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_FAILEDAUTHEXCEPTION_H
#define MAIN_FAILEDAUTHEXCEPTION_H

#include <exception>

class FailedAuthException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: Failed to auth user";
    }
};

#endif //MAIN_FAILEDAUTHEXCEPTION_H
