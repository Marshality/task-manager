//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_BASEFIELD_H
#define ORM_BASEFIELD_H

#include <string>
#include "BaseValidator.h"

class BaseField {
public:
    // Operator accepting data in string form
    inline virtual BaseField& operator=(const std::string& _data) {
        accept(_data);
        return *this;
    }

    // Basic method returning data in string form
    inline virtual std::string stringify() const = 0;

protected:
    // Basic method validating and accepting data in string form
    virtual void accept(const std::string& string) = 0;
};

#endif //ORM_BASEFIELD_H
