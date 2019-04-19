//
// Created by Святослав Кряжев on 19.04.2019.
//

#include <iostream>
#include "Manager.h"

std::unique_ptr<Manager> instance;

const Manager* Manager::getInstance()
{
    if (!instance) {
        instance = std::make_unique<Manager>("host=localhost port=2389 dbname=crab user=jason password=");
    }

    return instance.get();
}

Cursor Manager::execute(std::string&& query) const
{
    if (!isConnected()) {
        throw "Connection lost";
    }

    return Cursor(PQexec(connection, query.c_str()));
}