//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_BASEFIELD_H
#define ORM_BASEFIELD_H

#include <string>
#include "BaseValidator.h"

class BaseField {
public:
    explicit BaseField(BaseValidator* _validator) : validator(_validator) {}

    // Operator accepting data in string form
    inline virtual BaseField& operator=(const std::string& _data) {
        pass(_data);
        return *this;
    }

    // Basic method returning data in string form
    inline virtual std::string stringify() const = 0;

protected:
    BaseValidator* validator;

    // Basic method calling validator's pass method
    inline virtual void pass(const std::string& string) = 0;
};

#endif //ORM_BASEFIELD_H
