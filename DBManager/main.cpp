#include <iostream>

#include "Manager.h"

int main() {
    std::string s;

    try {
        Object* u = Manager::getInstance()->get("User", "id=1");
    } catch (const char* what) {
        std::cout << what << std::endl;
    }

    return 0;
}