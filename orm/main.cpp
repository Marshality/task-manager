#include <iostream>
#include <vector>
#include "IntegerField.h"
#include "IntegerValidator.h"
#include "CharField.h"

int main() {
    IntegerValidator validator;

    IntegerField integer(&validator);
    integer = 67;
    integer = "23";
    validator.check("34");

    auto s = integer.stringify();

    auto size = sizeof(IntegerField);
    std::cout << size << std::endl;

    return 0;
}