//
// Created by Святослав Кряжев on 14.04.2019.
//

#ifndef POSTGRESQL_ORM_USER_H
#define POSTGRESQL_ORM_USER_H

#include "Object.h"

class User : public Object {
public:
    User() = default;
    ~User() override = default;
};

#endif //POSTGRESQL_ORM_USER_H
