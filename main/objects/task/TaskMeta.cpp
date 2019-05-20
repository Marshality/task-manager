//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "Task.h"


template <>
Meta<Task>::Meta() :
        fieldsNames {
                "id",
                "user_id",
                "project_id",
                "title",
                "description",
                "creation_date",
                "deadline"
        } {}

template <>
const char* Meta<Task>::tableName() const {
    return "tasks";
}

template <>
bool Meta<Task>::hasField(const std::string& fieldName) const {
    return fieldsNames.find(fieldName) != fieldsNames.end();
}