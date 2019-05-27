//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "User.h"


template <>
Meta<User>::Meta() :
        BaseMeta(
                "users",
                {
                        "id",
                        "username",
                        "password",
                        "name",
                        "surname"
                }) {}