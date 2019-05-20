//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Storage.h"
#include "task/Task.h"


template <>
std::shared_ptr<Task> Storage::getOne<Task>(const std::string& query) const {
    auto result = this->query("SELECT * FROM ");

    return std::make_shared<Task>(result, 0);
}


template <>
std::shared_ptr<Set<Task>> Storage::getMany<Task>(const std::string& query) const {
    auto result = this->query("SELECT * FROM tasks");

    return std::make_shared<Set<Task>>(result);
}