#include <iostream>

#include "Manager.h"

int main() {
    psql::ConnectionConf conf = {
            .host = "localhost",
            .port = "2389",
            .db_name = "crab",
            .user = "jason",
            .password = ""
    };

    psql::Manager manager(conf);

    auto set = manager.execute(psql::Query("SELECT * FROM info;"));

    for (int i = 0; i < set.rows; ++i) {
        const char* gender = set.getAt(i, 0);
        const char* age = set.getAt(i, 1);
        printf("Gender: %s, Age: %s\n", gender, age);
    }

    return 0;
}