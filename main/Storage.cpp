//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Storage.h"


Storage::Storage(const std::string& connectionConfig) :
    connection(connectionConfig.data())
{

}

Storage& Storage::getInstance() {
    static Storage instance("host=localhost port=5432 dbname=ex user=ex_user password=12345678");

    return instance;
}