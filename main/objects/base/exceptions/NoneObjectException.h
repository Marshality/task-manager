//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_NONEOBJECTEXCEPTION_H
#define MAIN_NONEOBJECTEXCEPTION_H

#include <exception>
#include <string>


class NoneObjectException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: None object returned";
    }
};


#endif //MAIN_NONEOBJECTEXCEPTION_H
