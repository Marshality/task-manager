#include <iostream>
#include <vector>
//#include "fields/IntegerField.h"
#include "TemplateManager.h"

int main() {
    Project::objects().print();
    User::objects().print();

    return 0;
}