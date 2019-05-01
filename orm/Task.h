//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_TASK_H
#define ORM_TASK_H

#include "Model.h"
#include "CharValidator.h"
#include "DateValidator.h"

struct Task : public Model<Task> {
    using Model::objects;

    Task();

    CharField title;
    TextField description;
    DateField creation_date;
    DateField deadline;
};

#endif //ORM_TASK_H
