//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_TEXTVALIDATOR_H
#define ORM_TEXTVALIDATOR_H

#include "BaseValidator.h"
#include "TextField.h"

class TextValidator : public BaseValidator {
public:
    void pass(const std::string& string, BaseField* _field) const override {
        // Writing data to field
        if (_field) {
            auto field = dynamic_cast<TextField*>(_field);
            field->data = string;
        }
    }
};

#endif //ORM_TEXTVALIDATOR_H
