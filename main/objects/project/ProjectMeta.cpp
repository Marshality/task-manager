//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "Project.h"


template <>
struct Meta<Project> {
    const std::string tableName = "projects";
};