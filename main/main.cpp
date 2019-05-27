#include <iostream>
#include "Controller.h"
#include "user/User.h"

int main() {
    Controller controller;
    Request request = {
            .POST={
                    {"username", "shokolad"},
                    {"password", "12345678"},
                    {"title", "Helloworld"},
                    {"description", "Hello, I'm the night king"},
                    {"creation_date", "2019-05-27 12:00:43"}
            },
            .OPTIONS={
                { "name", "vasya" },
                { "surname", "pupkin" },
                { "birth_date", "now()" },
                { "avatar", "//beautiful" }
            }};

    std::cout << controller.createProject(request) << std::endl;

    return 0;
}