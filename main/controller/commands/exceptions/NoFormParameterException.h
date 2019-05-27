//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_NOFORMPARAMETEREXCEPTION_H
#define MAIN_NOFORMPARAMETEREXCEPTION_H

#include <exception>


class NoFormParameterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: Didn't find required form parameter while trying entering system";
    }
};

#endif //MAIN_NOFORMPARAMETEREXCEPTION_H
