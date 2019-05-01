//
// Created by Святослав Кряжев on 01.05.2019.
//

#ifndef ORM_META_H
#define ORM_META_H

#include <unordered_map>
#include <string>

#include "BaseValidator.h"

struct Meta {
    std::string tableName;
    std::unordered_map<std::string, BaseValidator*> fields;
};

#endif //ORM_META_H
