//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Connection.h"
#include "exceptions/PGException.h"

Connection::Connection(const char* config)
{
}

Connection::~Connection() {
}

Cursor Connection::execute(const std::string& query) const {
    if (!isActive()) {
        throw PGException(PQerrorMessage(connection));
    }

    return Cursor(PQexec(connection, query.c_str()));
}

Cursor Connection::executeWithParams(const std::string& query, const char* const* params) const {

}
