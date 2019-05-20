//
// Created by Святослав Кряжев on 13.05.2019.
//

#ifndef MAIN_DATABASE_H
#define MAIN_DATABASE_H

#include "Connection.h"
#include "Meta.h"

template <typename Object>
class Set;

class Storage {
public:
    // Main method
    static Storage& getInstance();

    template <typename Object>
    std::shared_ptr<Object> getOne(const std::string& query) const {
        std::string statement = "SELECT * FROM ";
        statement += Object::meta.tableName;

        auto result = this->query(statement);
    }

    template <typename Object>
    std::shared_ptr<Set<Object>> getMany(const std::string& query) const {
        std::string statement = "SELECT * FROM ";

    }

    std::shared_ptr<ResultSet> query(const std::string& query) const {
        return connection.execute(query);
    }

private:
    explicit Storage(const std::string& connectionConfig);

    Connection connection;
};


#endif //MAIN_DATABASE_H
