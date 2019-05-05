#include <iostream>

#include "DateField.h"
#include "DateValidator.h"
#include "DateTimeField.h"

int main() {
    DateValidator dateValidator;
    DateField dateField(&dateValidator);

    dateField = "01-02-0004";

    auto s = dateField.stringify();
    std::cout << s << std::endl;

    auto size = sizeof(DateTime);
    std::cout << size << std::endl;

    return 0;
}