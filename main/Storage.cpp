//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Storage.h"


Storage::Storage(const std::string& connectionConfig) :
    connection(connectionConfig.data())
{

}

Storage& Storage::getInstance() {
    static Storage instance("host=localhost port=5432 dbname=testdb user=yulia_plaksina password=");

    return instance;
}