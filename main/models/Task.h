//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_TASK_H
#define MAIN_TASK_H

#include "Model.h"

struct Task : public Model<Task> {
    using Model::objects;

    field id;
    field title;
    field description;
    field user_id;
    field project_id;
    field creation_date;
    field deadline;
};

//---------------------------------

template <>
struct Meta<Task> {
    Meta() {
        info.emplace("id");
        info.emplace("title");
        info.emplace("description");
        info.emplace("user_id");
        info.emplace("project_id");
        info.emplace("creation_date");
        info.emplace("deadline");
    }

    std::string tableName = "task";
    set info;
};


#endif //MAIN_TASK_H
