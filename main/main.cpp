#include <iostream>

#include "Task.h"

int main() {
    auto task = Task::objects.get(lol);
    task.id = "23";
    task.title = "debil";

    std::cout << "Hello, World!" << std::endl;
    return 0;
}