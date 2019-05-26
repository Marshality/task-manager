//
// Created by Святослав Кряжев on 26.05.2019.
//

#ifndef MAIN_EMPTYCREATEQUERY_H
#define MAIN_EMPTYCREATEQUERY_H

#include <exception>
#include <string>


class EmptyCreateQueryException : public std::exception {
public:
    EmptyCreateQueryException(const std::string& tableName) noexcept :
            _tableName(tableName.c_str()) {}

    const char* what() const noexcept override {
        std::string errMessage = "EXCEPTION: Tried to write to table: '";
        errMessage += _tableName;
        errMessage += "' within empty args";

        return errMessage.c_str();
    }

private:
    const char* _tableName;
};


#endif //MAIN_EMPTYCREATEQUERY_H
