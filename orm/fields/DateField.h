//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEFIELD_H
#define ORM_DATEFIELD_H

#include "BaseField.h"
#include "DateValidator.h"

class DateField : public BaseField {
public:
    inline DateField& operator=(const std::string& _data) override {
        accept(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return std::to_string(year) + '-' + std::to_string(month) + '-' + std::to_string(day);
    }

protected:
    unsigned short year = 0;
    unsigned char month = 0;
    unsigned char day = 0;

    void accept(const std::string& string) override {
        if (string[4] != '-' || string[7] != '-' || string.length() != 10) {
            throw "Wrong data format";
        }

        auto str = string.c_str();
        year = (unsigned short) read(str);
        month = (unsigned char) read(str + 5);
        if (month < 1 || month > 12) {
            throw "Invalid month value";
        }

        day = (unsigned char) read(str + 8);
    }

    int read(const char* str) {
        char* endPtr;
        auto result = std::strtol(str, &endPtr, 10);

        if (endPtr == str || (*endPtr != '-' && *endPtr != 0)) {
            throw "Invalid symbol found";
        }

        return (int) result;
    }
};

#endif //ORM_DATEFIELD_H
