//
// Created by Святослав Кряжев on 15.04.2019.
//

#ifndef POSTGRESQL_ORM_CREATOR_H
#define POSTGRESQL_ORM_CREATOR_H

#include "Object.h"
#include "User.h"

#define interface class

interface Creator {
public:
    Creator() = default;
    ~Creator() = default;

    virtual Object* create() = 0;
};

class UserCreator : public Creator {
public:
    UserCreator() = default;
    ~UserCreator() = default;

    Object* create() override {
        return new User();
    }
};

#endif //POSTGRESQL_ORM_CREATOR_H
