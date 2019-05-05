//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_CHARVALIDATOR_H
#define ORM_CHARVALIDATOR_H

#include "Validator.h"
#include "CharField.h"

class CharValidator : public Validator<Char> {
public:
    void pass(const std::string& string, Char* data) override {
        if (string.length() >= maxLength) {
            throw "Exceeds maxlength";
        }

        if (data) {
            data->data = string;
        }
    }

private:
    unsigned long maxLength = 256;
};

#endif //ORM_CHARVALIDATOR_H
