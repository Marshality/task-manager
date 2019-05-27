//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_BADQUERYEXCEPTION_H
#define MAIN_BADQUERYEXCEPTION_H

#include <string>
#include <exception>


class BadQueryException : public std::exception {
public:
    const char* what() const noexcept override {
        return "EXCEPTION: Bad query to database";
    }
};


#endif //MAIN_BADQUERYEXCEPTION_H
