#include <iostream>

#include "Task.h"

struct A {
    int min = 0;
    int max = 0;
};

struct B {
    B(A _a) : a(_a) {}
    A a;
    int count;
};


int main() {
    kwargs options;
    options.emplace("id", "23");
    options.emplace("title", "hyperloop");

//    auto task = Task::objects.get(options);
    IntegerValidator validator;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}