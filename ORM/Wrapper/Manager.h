//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <libpq-fe.h>
#include <string>

#include "Cursor.h"

class Manager {
public:
    explicit Manager(const char* config) : connection(PQconnectdb(config)) {}
    ~Manager() { PQfinish(connection); }

    const static Manager* getInstance();

    bool isConnected() const { return PQstatus(connection) == CONNECTION_OK; }
    Cursor execute(std::string&& query) const;

private:
    PGconn* connection;

};


#endif //ORM_MANAGER_H
