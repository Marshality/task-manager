//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_BASEVALIDATOR_H
#define ORM_BASEVALIDATOR_H

#include <string>

#define interface class

interface BaseValidator {
    virtual bool isValid(const std::string& string) = 0;
};

#endif //ORM_BASEVALIDATOR_H
