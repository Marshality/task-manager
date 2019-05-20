//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "Task.h"


template <>
Meta<Task>::Meta() :
        tableName_("tasks"),
        fieldsNames {
                "id",
                "user_id",
                "project_id",
                "title",
                "description",
                "creation_date",
                "deadline"
        } {}