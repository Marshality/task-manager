//
// Created by Святослав Кряжев on 13.05.2019.
//

#ifndef MAIN_DATABASE_H
#define MAIN_DATABASE_H

#include "Connection.h"


class Storage {
public:
    // Main method
    static Storage& getInstance();

    std::shared_ptr<ResultSet> query(const std::string& query) {
        return connection.execute(query);
    }

private:
    explicit Storage(const std::string& connectionConfig);

    Connection connection;
};


#endif //MAIN_DATABASE_H
