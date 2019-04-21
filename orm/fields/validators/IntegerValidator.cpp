//
// Created by Святослав Кряжев on 21.04.2019.
//

#include "IntegerValidator.h"

bool IntegerValidator::isValid(const std::string& string) {
    if (string.empty()) {
        return false;
    }

    if (!std::isdigit(string[0]) && string[0] != '-' && string[0] != '+') {
        return false;
    }

    char* endPtr;
    cache = std::strtoll(string.c_str(), &endPtr, 10);

    return (*endPtr == 0);
}

long long IntegerValidator::getCache() const {
    return cache;
}