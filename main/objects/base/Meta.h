//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_META_H
#define MAIN_META_H

#include "Types.h"

template <typename Object>
class Meta {
public:
    Meta();

    const std::string& tableName() const {
        return tableName_;
    }

    bool hasField(const std::string& fieldName) const {
        fieldsNames.find(fieldName) != fieldsNames.end();
    }

private:
    std::string tableName_;
    string_set fieldsNames;
};


#endif //MAIN_META_H
