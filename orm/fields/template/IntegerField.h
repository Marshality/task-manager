//
// Created by Святослав Кряжев on 02.05.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include "Field.h"

struct Integer {
    long long value;

    explicit operator std::string() const {
        return std::to_string(value);
    }
};

class IntegerField : public Field<Integer> {
    using Base = Field<Integer>;

public:
    using Base::Base;
    using Base::operator=;

    IntegerField& operator=(long long _value) {
        data.value = _value;
        return *this;
    }
};


#endif //ORM_INTEGERFIELD_H
