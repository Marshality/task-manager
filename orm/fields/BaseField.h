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
    explicit BaseField(BaseValidator* _validator) : validator(_validator) {}

    // Operator accepting data in string form
<<<<<<< HEAD
    inline BaseField& operator=(const std::string& _data) {
        validator->pass(_data, this);
=======
    inline virtual BaseField& operator=(const std::string& _data) {
        pass(_data);
>>>>>>> main_logic
        return *this;
    }

    // Basic method returning data in string form
    virtual std::string stringify() const = 0;

protected:
    BaseValidator* validator;
<<<<<<< HEAD
=======

    // Basic method calling validator's pass method
    inline virtual void pass(const std::string& string) = 0;
>>>>>>> main_logic
};

#endif //ORM_BASEFIELD_H
