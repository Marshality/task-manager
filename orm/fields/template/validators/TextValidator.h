//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_TEXTVALIDATOR_H
#define ORM_TEXTVALIDATOR_H

#include "Validator.h"
#include "TextField.h"

class TextValidator : public Validator<Text> {
public:
    void pass(const std::string& string, Text* data) override {
        if (data) {
            data->data = string;
        }
    }
};

#endif //ORM_TEXTVALIDATOR_H
