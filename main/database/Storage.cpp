//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Storage.h"

#include <fstream>
#include "exceptions/NoSuchFieldException.h"
#include "exceptions/EmptyCreateQueryException.h"


std::string readConnectionConfig() {
    std::ifstream file;
    file.open("../database_config.txt", std::fstream::out);

    std::string string;
    std::getline(file, string, '\0');

    file.close();

    return string;
}

Storage::Storage(const std::string& connectionConfig) :
        connection(connectionConfig.data()) {
}

Storage& Storage::getInstance() {
    static Storage instance(readConnectionConfig());

    return instance;
}

std::shared_ptr<ResultSet> Storage::getQuery(const string_map& kwargs, const BaseMeta& meta) const {
    std::string statement = "SELECT * FROM ";
    statement += meta.tableName();

    if (!kwargs.empty()) {
        statement += " WHERE ";

        int argsCount = static_cast<int>(kwargs.size());
        const char* params[argsCount];
        int i = 0;

        for (auto& pair : kwargs) {
            if (!meta.hasField(pair.first)) {
                throw NoSuchFieldException(meta.tableName(), pair.first);
            }

            statement += pair.first;
            statement += "=$";


            params[i] = pair.second.c_str();

            statement += std::to_string(++i);
            statement += " AND ";
        }

        for (int j = 0; j < 4; ++j) {
            statement.pop_back();
        }
        statement.back() = ';';

        return connection.executeWithParams(statement, params, argsCount);
    }

    return connection.execute(statement);
}

void Storage::createQuery(const string_map& kwargs, const BaseMeta& meta) const {
    if (kwargs.empty()) {
        throw EmptyCreateQueryException(meta.tableName());
    }

    std::string statement = "INSERT INTO ";
    statement += meta.tableName();
    statement += ' ';

    int argsCount = static_cast<int>(kwargs.size());
    const char* params[argsCount];
    int i = 0;

    std::string cols = "(";
    std::string values = "(";

    for (auto& pair : kwargs) {
        if (!meta.hasField(pair.first)) {
            throw NoSuchFieldException(meta.tableName(), pair.first);
        }

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