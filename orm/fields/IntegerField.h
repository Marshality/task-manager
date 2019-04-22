//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>

#include "validators/IntegerValidator.h"

class IntegerField {
public:
    IntegerField& operator=(long long _data);
    IntegerField& operator=(const std::string& _data);

private:
    long long data = 0;

    IntegerValidator validator;
};

#endif //ORM_INTEGERFIELD_H
