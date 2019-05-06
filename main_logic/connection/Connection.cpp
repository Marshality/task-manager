//
// Created by Святослав Кряжев on 19.04.2019.
//

#include <PGException.h>

#include "Connection.h"

Cursor Connection::execute(std::string&& query) const {
    if (!isActive()) {
        throw PGException(PQerrorMessage(connection));
    }

    return Cursor(PQexec(connection, query.c_str()));
}
