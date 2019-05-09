#include <iostream>
#include "DateTimeValidator.h"
#include "Set.h"

int main() {
    DateTimeValidator dateTimeValidator;
    DateTimeField dateTimeField(&dateTimeValidator);

    dateTimeField = "23-02-1999 03:14:56";

    std::cout << dateTimeField.stringify() << std::endl;

    auto size = sizeof(DateTimeField);

    std::cout << size << std::endl;
    return 0;
}