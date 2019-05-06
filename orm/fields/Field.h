//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_FIELD_H
#define ORM_FIELD_H

class Validator;

enum FieldType {
    INTEGER,

};

template <FieldType>
class Field {
    Validator* validator;
};

using IntegerField = Field<INTEGER>;

#endif //ORM_FIELD_H
