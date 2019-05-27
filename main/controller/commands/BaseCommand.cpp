//
// Created by Святослав Кряжев on 27.05.2019.
//

#include "BaseCommand.h"

#include <iostream>
#include "exceptions/FailedAuthException.h"
#include "exceptions/UsernameMismatchException.h"
#include "user/User.h"


std::shared_ptr<User> BaseCommand::authenticate() {
    auto username = _request.POST.find("username");
    auto password = _request.POST.find("password");

    auto endIt = _request.POST.end();
    if (username == endIt || password == endIt) {
        throw FailedAuthException();
    }

    try {
        auto user = User::getOne({{username->first, username->second}, {password->first, password->second}});
        user->approve();

        if (username->second != _request.OPTIONS["username"]) {
            throw UsernameMismatchException();
        }

        _request.AUTH.first = std::move(username->second);
        _request.AUTH.second = std::move(password->second);

        _request.POST.erase(username);
        _request.POST.erase(password);

        return user;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        throw FailedAuthException();
    }
}