//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef ORM_TIMEVALIDATOR_H
#define ORM_TIMEVALIDATOR_H

#include "BaseValidator.h"
#include "TimeField.h"

class TimeValidator : public virtual BaseValidator {
public:
    void pass(const std::string& string, BaseField* _field) const override {
        if (string.length() != 8 || string[2] != ':' || string[5] != ':') {
            throw "Wrong time format";
        }

        auto str = string.c_str();
        int hour = read(str);
        int minute = read(str + 3);
        int second = read(str + 6);

        validateTime(hour, minute, second);

        if (_field) {
            auto field = dynamic_cast<TimeField*>(_field);
            field->data.hour = static_cast<unsigned char>(hour);
            field->data.minute = static_cast<unsigned char>(minute);
            field->data.second = static_cast<unsigned char>(second);
        }
    }

private:
    int read(const char* str) const {
        char* endPtr;

        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != 0 && *endPtr != ':')) {
            throw "Invalid symbol found";
        }

        return (int) result;
    }

    void validateTime(int hour, int minute, int second) const {
        if (hour < 0 || hour > 23) {
            throw "Invalid hours value";
        }

        if (minute < 0 || minute > 59) {
            throw "Invalid minutes value";
        }

        if (second < 0 || second > 59) {
            throw "Invalid seconds value";
        }
    }
};

#endif //ORM_TIMEVALIDATOR_H
