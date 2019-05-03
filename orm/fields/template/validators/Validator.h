//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_VALIDATOR_H
#define ORM_VALIDATOR_H

#include "BaseValidator.h"

template <typename Type>
class Validator : public BaseValidator {
public:
    void check(const std::string& string) override {
        pass(string, nullptr);
    }

    virtual void pass(const std::string& string, Type* data) = 0;
};

#endif //ORM_VALIDATOR_H
