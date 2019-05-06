// Simple example of usage

#include <iostream>
#include "Connection.h"

int main() {
    Connection connection("host=localhost port=2389 dbname=crab user=jason password=");

    try {
        auto cursor = connection.execute("SELECT * FROM info;");
        while (cursor.next()) {
            std::cout << cursor.get(-1) << " " << cursor.get(1) << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }



    return 0;
}