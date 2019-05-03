//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_INTEGERVALIDATOR_H
#define ORM_INTEGERVALIDATOR_H

#include "IntegerField.h"
#include "BaseValidator.h"

class IntegerValidator : public Validator<Integer> {
public:
    void pass(const std::string& string, Integer* data) override {
        if (string.empty() && !std::isdigit(string[0]) && string[0] != '-' && string[0] != '+') {
            throw "Not an integer";
        }

        char* endPtr;
        auto temp = std::strtoll(string.c_str(), &endPtr, 10);

        if (*endPtr != 0) {
            throw "Met unacceptable symbols";
        }

        if (data) {
            data->value = temp;
        }
    }
};

#endif //ORM_INTEGERVALIDATOR_H
