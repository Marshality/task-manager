#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    Request request = {
            .GET={{"id", "1"}}
    };

    std::cout << controller.task(request) << std::endl;

    return 0;
}