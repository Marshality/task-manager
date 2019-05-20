//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "User.h"


template <>
Meta<User>::Meta() :
        fieldsNames {
                "id",
                "name",
                "surname",
                "birth_date",
                "avatar"
        } {}

template <>
const char* Meta<User>::tableName() const {
    return "users";
}

template <>
bool Meta<User>::hasField(const std::string& fieldName) const {
    return fieldsNames.find(fieldName) != fieldsNames.end();
}