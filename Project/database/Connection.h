//
// Created by Святослав Кряжев on 08.04.2019.
//

#ifndef DATABASE_TEST_CONNECTION_H
#define DATABASE_TEST_CONNECTION_H

#include <iostream>
#include <libpq-fe.h>

namespace psql {

    struct ConnectionConf {
        std::string host;
        std::string port;
        std::string db_name;
        std::string user;
        std::string password;
    };

    class Connection {
    public:
        explicit Connection(ConnectionConf& conf);
        ~Connection() { PQfinish(conn); }

        bool isEstablished() const { return PQstatus(conn) == CONNECTION_OK; }

        PGconn* get() const { return conn; }

    private:
        PGconn* conn = nullptr;
    };

}


#endif //DATABASE_TEST_CONNECTION_H
