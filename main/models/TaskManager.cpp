//
// Created by Святослав Кряжев on 06.05.2019.
//

#include "Manager.h"
#include "Task.h"


template <>
void Manager<Task>::save(Task& task) const {
    std::string statement = "(";
    statement += task.title.stringify();
    statement += task.description.stringify();
    statement += task.creation_date.stringify();
    statement += task.deadline.stringify();
    statement += ')';
}