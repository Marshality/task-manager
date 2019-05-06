#include <iostream>
<<<<<<< HEAD
#include "DateTimeValidator.h"
#include "Set.h"

int main() {
    DateTimeValidator dateTimeValidator;
    DateTimeField dateTimeField(&dateTimeValidator);

    dateTimeField = "23-02-1999 03:14:56";

    std::cout << dateTimeField.stringify() << std::endl;

    auto size = sizeof(DateTimeField);
=======
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
>>>>>>> main_logic
    std::cout << size << std::endl;
    return 0;
}