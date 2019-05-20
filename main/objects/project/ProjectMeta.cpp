//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "Meta.h"
#include "Project.h"


template <>
Meta<Project>::Meta() :
        tableName_("projects"),
        fieldsNames {
                "id",
                "owner_id",
                "title",
                "description",
                "creation_date"
        } {}