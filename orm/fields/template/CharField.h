//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include "Field.h"

struct Char {
    std::string data;

    explicit operator std::string() {
        return data;
    }
};

class CharField : Field<Char> {
    using Base = Field<Char>;

public:
    using Base::Base;
    using Base::operator=;
};

#endif //ORM_CHARFIELD_H
