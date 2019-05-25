#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    Request request = {
            .GET={{"id", "1"}}
    };

    std::cout << controller.project(request) << std::endl;

    return 0;
}