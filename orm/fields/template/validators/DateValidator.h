//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_DATEVALIDATOR_H
#define ORM_DATEVALIDATOR_H

#include "Validator.h"
#include "DateField.h"
#include <stdbool.h>

class DateValidator : public Validator<Date> {
public:
    void pass(const std::string& string, Date* data) override {
        if (string[2] != '-' || string[5] != '-' || string.length() != 10) {
            throw "Wrong data format";
        }

        auto str = string.c_str();

        int day = read(str);
        int month = read(str + 3);
        int year = read(str + 6);

        validateDate(day, month, year);

        if (data) {
            data->day = (unsigned char) day;
            data->month = (unsigned char) month;
            data->year = (unsigned short) year;
        }
    }

protected:
    int read(const char* str) {
        char* endPtr;

        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != 0 && *endPtr != '-')) {
            throw "Invalid symbol found";
        }

        return (int) result;
    }

    void validateDate(int day, int month, int year) {
        if (month < 1 || month > 12) {
            throw "Invalid month value";
        }

        if (month == 2) {
            if (day < 1 || day > 28 + isLeapYear(year)) {
                throw "Invalid day value";
            }

        } else {
            if (day < 1 || day > 30 + !(is30DayMonth(month))) {
                throw "Invalid day value";
            }
        }
    }

    bool is30DayMonth(int month) {
        return month == 4 || month == 6 || month == 9 || month == 11;
    }

    bool isLeapYear(int year) {
        return year % 4 == 0;
    }
};

#endif //ORM_DATEVALIDATOR_H
