//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEVALIDATOR_H
#define ORM_DATEVALIDATOR_H

#include "BaseValidator.h"

class DateValidator : public BaseValidator {
public:
    bool isValid(const std::string& string) const override {
        const char* left = string.c_str();
        const char* right = std::strstr(left, "-");
        if (!right || right - left > 4) {
            return false;
        }

        return true;
    }

private:
    int read(const char* begin) {
        char* endPtr;
        int value = (int) std::strtol(begin, &endPtr, 10);

        return (endPtr != begin) * value;
    }
};

#endif //ORM_DATEVALIDATOR_H
