//
// Created by Святослав Кряжев on 08.04.2019.
//

#include "Connection.h"

using namespace psql;

Connection::Connection(ConnectionConf& conf)
{
    conn = PQconnectdb((
            "host=" + conf.host + " " +
            "port=" + conf.port + " " +
            "dbname=" + conf.db_name + " "
            "user=" + conf.user + " " +
            "password=" + conf.password
            ).c_str());

    if (isEstablished()) {
        std::clog << "Connected" << std::endl;
    } else {
        std::clog << "Connection failed:\n" << PQerrorMessage(conn) << std::endl;
    }
}