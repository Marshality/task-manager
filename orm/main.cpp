#include <iostream>
#include <vector>
#include "Model.h"
#include "TextField.h"
#include "IntegerField.h"
#include "CharField.h"
#include "DateField.h"

int main() {
    DateField dateField;

    dateField = "2011-05-33";


    auto s = dateField.stringify();


    auto size = sizeof(DateField);
    std::cout << size << std::endl;
    std::cout << s << std::endl;
    return 0;
}