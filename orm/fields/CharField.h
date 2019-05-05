//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include "BaseField.h"

class CharField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return data;
    }

protected:
    std::string data;

    friend class CharValidator;
};

#endif //ORM_CHARFIELD_H
