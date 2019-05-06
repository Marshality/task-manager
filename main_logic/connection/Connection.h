//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <libpq-fe.h>
#include <string>

#include "Cursor.h"

class Connection {
public:
    explicit Connection(const char* config) : connection(PQconnectdb(config)) {}
    ~Connection() { PQfinish(connection); }

    bool isActive() const { return PQstatus(connection) == CONNECTION_OK; }

    Cursor execute(std::string&& query) const;

private:
    PGconn* connection;
};


#endif //ORM_MANAGER_H
