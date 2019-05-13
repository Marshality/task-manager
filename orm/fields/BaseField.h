//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_BASEFIELD_H
#define ORM_BASEFIELD_H

#include <string>
#include "BaseValidator.h"

struct BaseData {};

class BaseField {
public:
    BaseField() = default;
    explicit BaseField(BaseValidator* _validator) : validator(_validator) {}

    // Operator accepting data in string form
    inline BaseField& operator=(const std::string& _data) {
        validator->pass(_data, this);
        return *this;
    }

    // Basic method returning data in string form
    virtual std::string stringify() const = 0;

protected:
    BaseValidator* validator;
};

#endif //ORM_BASEFIELD_H
