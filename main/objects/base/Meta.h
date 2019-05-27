//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_META_H
#define MAIN_META_H

#include "Types.h"


class BaseMeta {
public:
    BaseMeta(std::string&& tableName, string_set&& fieldsNames) :
        _tableName(std::move(tableName)), _fieldsNames(fieldsNames) {}

    const std::string& tableName() const {
        return _tableName;
    }

    bool hasField(const std::string& fieldName) const {
        return _fieldsNames.find(fieldName) != _fieldsNames.end();
    }

protected:
    std::string _tableName;
    string_set _fieldsNames;
};


template <typename Object>
struct Meta : public BaseMeta {
    Meta();
};


#endif //MAIN_META_H
