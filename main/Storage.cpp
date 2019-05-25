//
// Created by Святослав Кряжев on 13.05.2019.
//

#include "Storage.h"

#include <fstream>


std::string readConnectionConfig() {
    std::ifstream file;
    file.open("../database_config.txt", std::fstream::out);

    std::string string;
    std::getline(file, string, '\0');

    file.close();

    return string;
}

Storage::Storage(const std::string& connectionConfig) :
        connection(connectionConfig.data()) {
}

Storage& Storage::getInstance() {
    static Storage instance(readConnectionConfig());

    return instance;
}