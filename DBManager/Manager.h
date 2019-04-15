//
// Created by Святослав Кряжев on 15.04.2019.
//

#ifndef POSTGRESQL_ORM_MANAGER_H
#define POSTGRESQL_ORM_MANAGER_H

#include <unordered_map>
#include "Object.h"
#include "Fields.h"
#include "Creator.h"

struct Meta {
    std::string tableName;
    std::unordered_map<std::string, Field> fields;
};

struct Controller {
    struct Meta metaInfo;
    Creator* creator;
};

class Manager {
public:
    const static Manager* getInstance();
    Object* get(std::string&& table, std::string& query) const;

private:
    std::unordered_map<std::string, Controller> tables;
};


#endif //POSTGRESQL_ORM_MANAGER_H
