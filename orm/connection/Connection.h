//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <libpq-fe.h>
#include <string>
#include "PGException.h"

#include "Cursor.h"

class Connection {
public:
    explicit Connection(const char* config) : connection(PQconnectdb(config)) {}
    ~Connection() { PQfinish(connection); }

    bool isActive() const { return PQstatus(connection) == CONNECTION_OK; }

    Cursor execute(const std::string& query) const {
    	if (!isActive()) {
    		throw PGException(PQerrorMessage(connection));
    	}

    	return Cursor(PQexec(connection, query.c_str()));
    }

private:
    PGconn* connection;
};


#endif //ORM_MANAGER_H
