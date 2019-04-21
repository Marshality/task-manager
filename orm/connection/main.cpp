// Simple example of usage

#include <iostream>
#include "Connection.h"

int main() {
    auto manager = wrapper::Manager::getInstance();

    try {
        auto cursor = manager->execute("SELECT * FROM info;");
        while (cursor.next()) {
            std::cout << cursor.get(0) << " " << cursor.get(1) << std::endl;
        }
    } catch (const char* e) {
        std::cout << e << std::endl;
    }

    return 0;
}