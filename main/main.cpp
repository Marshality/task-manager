#include <iostream>
#include "Controller.h"
#include "user/User.h"

int main() {
    Controller controller;
    Request request = {
            .POST={
                    {"username", "joycasino"},
                    {"password", "qwerty"},
                    {"form", "login"},
//                    {"name", "Marik"},
//                    {"surname", "Komarik"}
//                    {"project_id","3"},
//                    {"title", "Helloworld"},
//                    {"description", "Hello, I'm the night king"},
//                    {"creation_date", "2019-05-27 12:00:00"},
//                    {"deadline", "2019-05-27 18:00:00"}
            },
            .OPTIONS={
                { "name", "vasya" },
                { "surname", "pupkin" },
                { "birth_date", "now()" },
                { "avatar", "//beautiful" }
            }};

    std::cout << controller.userSuccess(request) << std::endl;

    return 0;
}