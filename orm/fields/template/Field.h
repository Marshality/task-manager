//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_FIELD_H
#define ORM_FIELD_H

#include <string>
#include "Validator.h"

template <typename Type>
class Field {
public:
    Field(Validator<Type>* _validator) : validator(_validator) {}

    Field& operator=(const std::string& _data) {
        validator->pass(_data, &data);
        return *this;
    }

    std::string stringify() const {
        return std::string(data);
    }

protected:
    Type data;
    Validator<Type>* validator;
};

#endif //ORM_FIELD_H
