//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_BASEVALIDATOR_H
#define ORM_BASEVALIDATOR_H

#include <string>

class BaseValidator {
public:
    // Polymorphic function that validates string input
    virtual bool isValid(const std::string& string) const = 0;

    virtual bool val() {
        return true;
    }
};

#endif //ORM_BASEVALIDATOR_H
