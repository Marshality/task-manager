//
// Created by Святослав Кряжев on 09.04.2019.
//

#ifndef DATABASE_TEST_QUERY_H
#define DATABASE_TEST_QUERY_H

#include <string>

#include "Connection.h"
#include "ResultSet.h"

namespace psql {
    class Query {
    public:
        explicit Query(const char* _statement) : statement(_statement) { std::cout << "Query ctr\n"; }
        Query() = default;
        ~Query() { std::cout << "Query dtr\n"; }

        void setStatement(const char* _statement) { statement = _statement; }

        ResultSet execute(Connection& connection) { return ResultSet(PQexec(connection.get(), statement.c_str())); }

    private:
        std::string statement;
    };
}



#endif //DATABASE_TEST_QUERY_H
