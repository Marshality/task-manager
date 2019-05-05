//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_TEXT_H
#define ORM_TEXT_H

#include "CharField.h"

struct Text : public Char {};

class TextField : public Field<TextField> {
    using Base = Field<TextField>;

public:
    using Base::Base;
    using Base::operator=;
};

#endif //ORM_TEXT_H
