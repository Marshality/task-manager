//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>
#include "BaseField.h"

struct Integer : public BaseData {
    long long value = 0;
};

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
    Integer data;

    friend class IntegerValidator;
};

#endif //ORM_INTEGERFIELD_H
