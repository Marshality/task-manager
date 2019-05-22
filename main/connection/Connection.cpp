//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Connection.h"

#include </usr/local/Cellar/libpq/11.1/include/libpq-fe.h>
#include "exceptions/PGException.h"

Connection::Connection(const char* config) :
        connection(PQconnectdb(config)) {}

Connection::~Connection() {
    PQfinish(connection);
}

bool Connection::isActive() const {
    return PQstatus(connection) == ConnStatusType::CONNECTION_OK;
}

std::shared_ptr<ResultSet> Connection::execute(const std::string& query) const {
    if (!isActive()) {
        throw PGException(PQerrorMessage(connection));
    }

    return std::make_shared<ResultSet>(PQexec(connection, query.c_str()));
}

std::shared_ptr<ResultSet>
Connection::executeWithParams(const std::string& query, const char** params, int argsCount) const {
    if (!isActive()) {
        throw PGException(PQerrorMessage(connection));
    }

    return std::make_shared<ResultSet>(PQexecParams(connection, query.c_str(), argsCount, NULL, params, NULL, NULL, 0));
}
