//
// Created by Святослав Кряжев on 13.04.2019.
//

#ifndef POSTGRESQL_ORM_MODEL_H
#define POSTGRESQL_ORM_MODEL_H

#define interface class

interface Object {
public:
    Object() = default;
    virtual ~Object() = 0;
};

#endif //POSTGRESQL_ORM_MODEL_H
