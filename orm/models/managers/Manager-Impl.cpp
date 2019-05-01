//
// Created by Святослав Кряжев on 26.04.2019.
//

#include "_Manager.h"
#include "TextValidator.h"
#include "CharValidator.h"
#include "DateValidator.h"
#include "Task.h"


template class Manager<Task>;

template <>
Manager<Task>::Manager();

template <>
Task Manager<Task>::get(const std::string& options) const;

template <>
Manager<Task>::Manager() {
    metaInfo.tableName = "task";

    metaInfo.fields.emplace("title", new CharValidator);
    metaInfo.fields.emplace("description", new TextValidator);
    metaInfo.fields.emplace("creation_date", new DateValidator);
    metaInfo.fields.emplace("deadline", new DateValidator);
}

template <>
Task Manager<Task>::get(const std::string& options) const {

}