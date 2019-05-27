//
// Created by Святослав Кряжев on 25.05.2019.
//

#ifndef MAIN_NOSUCHFIELDEXCEPTION_H
#define MAIN_NOSUCHFIELDEXCEPTION_H

#include <exception>
#include <string>


class NoSuchFieldException : public std::exception {
public:
    NoSuchFieldException(const std::string& tableName, const std::string& fieldName) noexcept :
            _tableName(tableName.c_str()),
            _nonexistentFieldName(fieldName.c_str()) {}

    const char* what() const noexcept override {
        std::string errMessage = "EXCEPTION: Tried to interact with table: '";
        errMessage += _tableName;
        errMessage += "' within field name: '";
        errMessage += _nonexistentFieldName;
        errMessage += "'";

        return errMessage.c_str();
    }

private:
    const char* _tableName;
    const char* _nonexistentFieldName;
};


#endif //MAIN_NOSUCHFIELDEXCEPTION_H
