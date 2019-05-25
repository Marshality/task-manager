#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    Request request = {
            .OPTIONS={{"owner_id", "1"}}
    };

    std::cout << controller.projectList(request) << std::endl;

    return 0;
}