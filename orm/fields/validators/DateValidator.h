//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEVALIDATOR_H
#define ORM_DATEVALIDATOR_H

#include "BaseValidator.h"
#include "DateField.h"

class DateValidator : public virtual BaseValidator {
public:
<<<<<<< HEAD
    void pass(const std::string& string, BaseField* _field) const override {
        if (string.length() != 10 || string[2] != '-' || string[5] != '-') {
=======
    void pass(const std::string& string, BaseField* _field) override {
        if (string[2] != '-' || string[5] != '-' || string.length() != 10) {
>>>>>>> main_logic
            throw "Wrong data format";
        }

        auto str = string.c_str();

        int day = read(str);
<<<<<<< HEAD
        int month = read(str + 3);
        int year = read(str + 6);

        validateDate(day, month, year);

        // Writing data to field
        if (_field) {
            auto field = dynamic_cast<DateField*>(_field);
            field->data.day = (unsigned char) day;
            field->data.month = (unsigned char) month;
            field->data.year = (unsigned short) year;
        }
    }

protected:
    int read(const char* str) const {
        char* endPtr;

        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != 0 && *endPtr != '-')) {
            throw "Invalid symbol found";
        }

        return (int) result;
    }

    void validateDate(int day, int month, int year) const {
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

    bool is30DayMonth(int month) const {
        return month == 4 || month == 6 || month == 9 || month == 11;
    }

    bool isLeapYear(int year) const {
        return year % 4 == 0;
=======

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
    int read(const char* str) {
        char* endPtr;
        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != '-' && *endPtr != 0)) {
            throw "Invalid symbol found";
        }

        return (int) result;
>>>>>>> main_logic
    }
};

#endif //ORM_DATEVALIDATOR_H
