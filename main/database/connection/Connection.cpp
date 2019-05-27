//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Connection.h"

#include <libpq-fe.h>
#include "exceptions/PGException.h"
#include "exceptions/BadQueryException.h"

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

    auto res = std::make_shared<ResultSet>(PQexec(connection, query.c_str()));
    if (!res->isOk()) {
        throw BadQueryException();
    }

    return res;
}

std::shared_ptr<ResultSet>
Connection::executeWithParams(const std::string& query, const char** params, int argsCount) const {
    if (!isActive()) {
        throw PGException(PQerrorMessage(connection));
    }

    auto res = std::make_shared<ResultSet>(PQexecParams(connection, query.c_str(), argsCount, NULL, params, NULL, NULL, 0));
    if (!res->isOk()) {
        throw BadQueryException();
    }

    return res;
}
