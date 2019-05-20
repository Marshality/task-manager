//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef PSQL_CONNECTION_H
#define PSQL_CONNECTION_H

#include <string>

#include "ResultSet.h"
#include "exceptions/PGException.h"

struct pg_conn;

class Connection {
public:
    explicit Connection(const char* config);
    ~Connection();

    bool isActive() const;

    std::shared_ptr<ResultSet> execute(const std::string& query) const;
    std::shared_ptr<ResultSet> executeWithParams(const std::string& query, const char** params, int argsCount) const;

private:
    pg_conn* connection;
};


#endif //PSQL_CONNECTION_H
