//
// Created by Святослав Кряжев on 15.04.2019.
//

#include "Manager.h"

static std::unique_ptr<Manager> instance = nullptr;

const Manager* Manager::getInstance() {
    if (!instance) {
        instance = std::make_unique<Manager>();
    }

    return instance.get();
}

Object* Manager::get(std::string&& table, std::string&& params) const {
    auto it1 = tables.find(table);
    if (it1 == tables.end()) {
        throw "Not found.";
    }

    auto meta = it1->second.metaInfo;
    auto creator = it1->second.creator;

    // сначала распарсить query
    auto it2 = meta.fields.find(params);
    if (it2 == meta.fields.end()) {
        throw "Not found.";
    }

    if (!it2->second.validate()) {
        throw "Incorrect.";
    }

    // Сборка запроса + экранирование
    std::string query = "SELECT * FROM " + meta.tableName + " WHERE " + params;

    // Обращение к БД
    auto set = PSQL.query(query);

    creator->create();
}
