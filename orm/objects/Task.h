//
// Created by Святослав Кряжев on 20.04.2019.
//

#ifndef ORM_TASK_H
#define ORM_TASK_H

#include "TaskManager.h"
#include "CharField.h"

class Task {
public:
    static TaskManager* objects();

    void save();

    CharField title;
    CharField description;
    CharField creation_date;
    CharField expiration_date;

    // TODO(svyat): Add relational fields

private:
    unsigned long id;

};

#endif //ORM_TASK_H
