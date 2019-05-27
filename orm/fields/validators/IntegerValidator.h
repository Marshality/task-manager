//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERVALIDATOR_H
#define ORM_INTEGERVALIDATOR_H

#include "BaseValidator.h"
#include "IntegerField.h"

class IntegerValidator : public BaseValidator {
public:
    void pass(const std::string& string, BaseField* _field) const override {
        if (string.empty() && !std::isdigit(string[0]) && string[0] != '-' && string[0] != '+') {
            throw "Not an integer";
        }

        char* endPtr;
        auto temp = std::strtoll(string.c_str(), &endPtr, 10);

        if (*endPtr != 0) {
            throw "Met unacceptable symbols";
        }

        // Writing data to field
        if (_field) {
            auto field = dynamic_cast<IntegerField*>(_field);
            field->data.value = temp;
        }
    }

    bool needsScreening() override {
        return false;
    };
};

#endif //ORM_INTEGERVALIDATOR_H
