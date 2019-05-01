//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERVALIDATOR_H
#define ORM_INTEGERVALIDATOR_H

#include "BaseValidator.h"

class IntegerValidator : public BaseValidator {
public:
    bool isValid(const std::string& string) const override {
        if (string.empty()) {
            return false;
        }

        if (!std::isdigit(string[0]) && string[0] != '-' && string[0] != '+') {
            return false;
        }

        char* endPtr;
        std::strtoll(string.c_str(), &endPtr, 10);

        return (*endPtr == 0);
    }
};

#endif //ORM_INTEGERVALIDATOR_H
