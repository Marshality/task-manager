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

    template <typename Object> std::shared_ptr<ResultSet> getQuery(const string_map& kwargs) const;
};

// Implementation

// Public methods

template <typename Object>
std::shared_ptr<Object> Storage::getOne(const string_map& kwargs) const {
    return std::make_shared<Object>(getQuery<Object>(kwargs), 0);
}

template <typename Object>
std::shared_ptr<Set<Object>> Storage::getMany(const string_map& kwargs) const {
    return std::make_shared<Set<Object>>(getQuery<Object>(kwargs));
}

// Private methods

template <typename Object>
Meta<Object>& Storage::getMeta() const {
    static Meta<Object> metaInstance;

    return metaInstance;
}

template <typename Object>
std::shared_ptr<ResultSet> Storage::getQuery(const string_map& kwargs) const {
    std::string statement = "SELECT * FROM ";
    statement += getMeta<Object>().tableName();

    if (!kwargs.empty()) {
        statement += " WHERE ";

        int argsCount = static_cast<int>(kwargs.size());
        const char* params[argsCount];
        int i = 0;

        for (auto& pair : kwargs) {
            statement += pair.first;
            statement += "=$";

            params[i] = pair.second.c_str();

            statement += std::to_string(++i);
            statement += ',';
        }

        statement.back() = ';';

        return connection.executeWithParams(statement, params, argsCount);
    }

    return connection.execute(statement);
}

template <typename Object>
void Storage::create(const string_map& kwargs) const {
    if (kwargs.empty()) {
        return;
    }

    std::string statement = "INSERT INTO ";
    statement += getMeta<Object>().tableName();
    statement += ' ';

    int argsCount = static_cast<int>(kwargs.size());
    const char* params[argsCount];
    int i = 0;

    std::string cols = "(";
    std::string values = "(";

    for (auto& pair : kwargs) {
        cols += pair.first;
        values += '$';

        params[i] = pair.second.c_str();

        values += std::to_string(++i);
        cols += ',';
        values += ',';
    }

    cols.back() = ')';
    values.back() = ')';

    statement += cols;
    statement += " VALUES ";
    statement += values;

    connection.executeWithParams(statement, params, argsCount);
}


#endif //MAIN_DATABASE_H
