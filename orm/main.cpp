#include <iostream>
#include <vector>
#include "Model.h"
#include "TextField.h"
#include "IntegerField.h"
#include "IntegerValidator.h"
#include "CharField.h"
#include "DateField.h"

int main() {
//    DateField dateField;
//
//    dateField = "24-01-1999";

    IntegerValidator validator;
//    auto validator = new IntegerValidator;
    IntegerField integer(&validator);

    integer = "12446";


    auto s = integer.stringify();
    //auto s = dateField.stringify();


    auto size = sizeof(IntegerField);
    std::cout << size << std::endl;
    std::cout << s << std::endl;
    return 0;
}