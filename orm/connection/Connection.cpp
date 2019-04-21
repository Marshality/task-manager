//
// Created by Святослав Кряжев on 19.04.2019.
//

#include <iostream>
#include "Connection.h"

std::unique_ptr<Connection> instance;

const Connection* Connection::getInstance()
{
    if (!instance) {
        instance = std::make_unique<Connection>("host=localhost port=2389 dbname=crab user=jason password=");
    }

    return instance.get();
}

Cursor Connection::execute(std::string&& query) const
{
    if (!isActive()) {
        throw "Connection is lost";
    }

    return Cursor(PQexec(connection, query.c_str()));
}