#include <iostream>
#include "Controller.h"
#include "user/User.h"

int main() {
//    Controller controller;
//    Request request = {
//            .OPTIONS={{"owner_id", "1"}}
//    };
//
//    std::cout << controller.index(request) << std::endl;

    User::create({
        {"name", "john"},
        {"surname", "smith"},
        {"birth_date", "now()"},
        {"avatar", "//none_as_always"}
    });

    return 0;
}