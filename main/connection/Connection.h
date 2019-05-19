//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef PSQL_CONNECTION_H
#define PSQL_CONNECTION_H

#include <libpq-fe.h>
#include <string>

#include "ResultSet.h"
#include "exceptions/PGException.h"


class Connection {
public:
    explicit Connection(const char* config) : connection(PQconnectdb(config)) {}
    ~Connection() { PQfinish(connection); }

    bool isActive() const { return PQstatus(connection) == ConnStatusType::CONNECTION_OK; }

    std::shared_ptr<ResultSet> execute(const std::string& query) const {
        if (!isActive()) {
            throw PGException(PQerrorMessage(connection));
        }

        return std::make_shared<ResultSet>(PQexec(connection, query.c_str()));
    }

//    ResultSet executeWithParams(const std::string& query, const char* const* params) const;

private:
    PGconn* connection;
};


#endif //PSQL_CONNECTION_H
