//
// Created by Святослав Кряжев on 21.04.2019.
//

#include "IntegerField.h"

IntegerField& IntegerField::operator=(long long _data) {
    data = _data;
    return *this;
}

IntegerField& IntegerField::operator=(const std::string& _data) {
    if (!validator.isValid(_data)) {
        throw "Non integer";
    }

    data = validator.getCache();

    return *this;
}