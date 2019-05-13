//
// Created by Святослав Кряжев on 12.05.2019.
//

#ifndef ORM_TASK_H
#define ORM_TASK_H

#include "Model.h"
#include "IntegerField.h"

struct Task : public Model<Task> {
    using Model::objects;

    IntegerField id = IntegerField::link(objects.constraints.id);

    struct Constraints {
        IntegerField::Constraints id {
            .max_value = 1,
            .min_value = -1
        };
    };
};

#endif //ORM_TASK_H
