#include <iostream>
#include "Wrapper/Manager.h"
#include "Wrapper/Cursor.h"

int main()
{
    try {
        auto cursor = Manager::getInstance()->execute("SELECT * FROM info;");
        while (cursor.next()) {
            std::cout << cursor.get(0) << " " << cursor.get(1) << std::endl;
        }
    } catch(const char* e) {
        std::cout << e << std::endl;
    }

    return 0;
}