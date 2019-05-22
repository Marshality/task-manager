#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    Request request;

    std::cout << controller.task(request) << std::endl;

    return 0;
}