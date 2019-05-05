//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>
#include "BaseField.h"

class IntegerField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    inline IntegerField& operator=(long long _data) {
        data = _data;
        return *this;
    }

    std::string stringify() const override {
        return std::to_string(data);
    }

private:
    long long data = 0;

    friend class IntegerValidator;
};

#endif //ORM_INTEGERFIELD_H
