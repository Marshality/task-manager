//
// Created by Святослав Кряжев on 22.04.2019.
//

#ifndef CONNECTION_PGEXCEPTION_H
#define CONNECTION_PGEXCEPTION_H

#include <exception>
#include <string>

class PGException : public std::exception {
public:
    explicit PGException(const char* _errorMessage) : errorMessage(_errorMessage) {}

    const char* what() const noexcept override { return errorMessage.c_str(); }

private:
    std::string errorMessage;
};

#endif //CONNECTION_PGEXCEPTION_H
