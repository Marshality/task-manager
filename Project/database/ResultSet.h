//
// Created by Святослав Кряжев on 10.04.2019.
//

#ifndef DATABASE_TEST_RESULTSET_H
#define DATABASE_TEST_RESULTSET_H

#include <libpq-fe.h>
#include <iostream>

namespace psql {
    class ResultSet {
    public:
        explicit ResultSet(PGresult* _result) : result(_result) { std::cout << "ResultSet ctr\n"; build(); }
        ~ResultSet() { PQclear(result); std::cout << "ResultSet dtr\n"; }

        const char* getAt(int i, int j) const { return PQgetvalue(result, i, j); }

        int rows = 0;
        int cols = 0;

    private:
        PGresult* result = nullptr;

        void build() {
            rows = PQntuples(result);
            cols = PQnfields(result);
        }
    };
}


#endif //DATABASE_TEST_RESULTSET_H
