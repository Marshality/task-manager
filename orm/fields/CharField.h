//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include "BaseField.h"

struct Char {
    std::string data;
};

class CharField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return data.data;
    }

private:
    Char data;

    friend class CharValidator;
};

#endif //ORM_CHARFIELD_H
