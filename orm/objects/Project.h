//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_PROJECT_H
#define ORM_PROJECT_H

#include "ProjectManager.h"

#include "CharField.h"

class Project {
public:
    static ProjectManager* objects();

    void save();

    CharField title;
    CharField description;
    CharField creation_date;


    // TODO(svyat): Add relational fields
};

#endif //ORM_PROJECT_H
