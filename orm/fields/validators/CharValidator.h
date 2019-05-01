//
// Created by Святослав Кряжев on 26.04.2019.
//

#ifndef ORM_CHARVALIDATOR_H
#define ORM_CHARVALIDATOR_H

#include "BaseValidator.h"

class CharValidator : public BaseValidator {
public:
    bool isValid(const std::string& string) const override {
        return string.length() <= maxLength;
    }

private:
    unsigned long maxLength;
};

#endif //ORM_CHARVALIDATOR_H
