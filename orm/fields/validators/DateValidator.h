//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEVALIDATOR_H
#define ORM_DATEVALIDATOR_H

#include "BaseValidator.h"
#include "DateField.h"

class DateValidator : public BaseValidator {
public:
    void pass(const std::string& string, BaseField* _field) const override {
        if (string[2] != '-' || string[5] != '-' || string.length() != 10) {
            throw "Wrong data format";
        }

        auto str = string.c_str();

        int day = read(str);

        int month = read(str + 3);
        if (month < 1 || month > 12) {
            throw "Invalid month value";
        }

        int year = (unsigned short) read(str + 6);

        if (_field) {
            auto field = dynamic_cast<DateField*>(_field);
            field->day = (unsigned char) day;
            field->month = (unsigned char) month;
            field->year = (unsigned short) year;
        }
    }

private:
    int read(const char* str) const {
        char* endPtr;
        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != '-' && *endPtr != 0)) {
            throw "Invalid symbol found";
        }

        return (int) result;
    }
};

#endif //ORM_DATEVALIDATOR_H
