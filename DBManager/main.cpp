#include <iostream>

#include "Manager.h"

int main() {
    std::string s;
    Object* u = Manager::getInstance()->get("", s);

    return 0;
}