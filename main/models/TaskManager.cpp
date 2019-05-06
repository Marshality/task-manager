//
// Created by Святослав Кряжев on 06.05.2019.
//

#include "Manager.h"
#include "Task.h"

template <>
Task Manager<Task>::get(const map& kwargs) const {
    return Task();
}

template <>
void Manager<Task>::save(Model<Task>& model) const {
    auto task = static_cast<Task&>(model);

    std::string statement;
    statement += "title=";
    statement += task.title;
    statement += "description=";
    statement += task.description;
    statement +=
}