//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_BASEVALIDATOR_H
#define ORM_BASEVALIDATOR_H

#include <string>

class BaseValidator {
public:
    virtual void check(const std::string& string) = 0;
};

#endif //ORM_BASEVALIDATOR_H
