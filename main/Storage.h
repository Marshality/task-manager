//
// Created by Святослав Кряжев on 13.05.2019.
//

#ifndef MAIN_DATABASE_H
#define MAIN_DATABASE_H

#include "Connection.h"
#include "Types.h"
#include "Meta.h"


template <typename Object>
class Set;

class Storage {
public:
    // Main method
    static Storage& getInstance();

    template <typename Object> std::shared_ptr<Object> getOne(const string_map& kwargs) const;
    template <typename Object> std::shared_ptr<Set<Object>> getMany(const string_map& kwargs) const;

    template <typename Object> void create(const string_map& kwargs) const;

private:
    explicit Storage(const std::string& connectionConfig);

    Connection connection;

    template <typename Object> Meta<Object>& getMeta() const;

    std::shared_ptr<ResultSet> getQuery(const string_map& kwargs, const BaseMeta& meta) const;
    void createQuery(const string_map& kwargs, const BaseMeta& meta) const;
};

// Implementation template methods

// Public methods

template <typename Object>
std::shared_ptr<Object> Storage::getOne(const string_map& kwargs) const {
    return std::make_shared<Object>(getQuery(kwargs, getMeta<Object>()), 0);
}

template <typename Object>
std::shared_ptr<Set<Object>> Storage::getMany(const string_map& kwargs) const {
    return std::make_shared<Set<Object>>(getQuery(kwargs, getMeta<Object>()));
}

template <typename Object> void Storage::create(const string_map& kwargs) const {
    createQuery(kwargs, getMeta<Object>());
}

// Private methods

template <typename Object>
Meta<Object>& Storage::getMeta() const {
    static Meta<Object> metaInstance;

    return metaInstance;
}


#endif //MAIN_DATABASE_H
