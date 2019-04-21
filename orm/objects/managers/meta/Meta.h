//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_META_H
#define ORM_META_H

#include <string>
#include <unordered_map>

#include "BaseValidator.h"

struct Meta {
    std::string tableName;
    std::unordered_map<std::string, BaseValidator*> fields;
};

#endif //ORM_META_H
