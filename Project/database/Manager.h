//
// Created by Святослав Кряжев on 10.04.2019.
//

#ifndef DATABASE_TEST_MANAGER_H
#define DATABASE_TEST_MANAGER_H

#include <libpq-fe.h>

#include "Connection.h"
#include "Query.h"
#include "ResultSet.h"

namespace psql {
    class Manager {
    public:
        Manager(ConnectionConf& conf) : connection(conf) { try {if (connection.isEstablished()) throw "pizdec";}
        catch (const char*) { std::cout << "Da, pizdec" << std::endl; }}
        ResultSet execute(Query query) { return ResultSet(query.execute(connection)); }

    private:
        Connection connection;

    };
}


#endif //DATABASE_TEST_MANAGER_H
