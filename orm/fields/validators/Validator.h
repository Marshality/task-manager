//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_VALIDATOR_H
#define ORM_VALIDATOR_H

#include <string>
#include "Field.h"

class Validator {
    template <typename Field>
    void pass(const std::string& string, Field* field);
};


template <>
void Validator::pass(const std::string& string, IntegerField* field) {

}

#endif //ORM_VALIDATOR_H
