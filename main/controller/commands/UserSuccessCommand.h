//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_DELETEUSERCOMMAND_H
#define MAIN_DELETEUSERCOMMAND_H

#include "BaseCommand.h"
#include "exceptions/NoFormParameterException.h"
#include "exceptions/PasswordMismatchException.h"


class UserSuccessCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto formType = _request.POST.find("form");

        if (formType == _request.POST.end()) {
            throw NoFormParameterException();
        }

        if (formType->second == "sign_up") {
            auto password1 = _request.POST.find("password1");
            auto password2 = _request.POST.find("password2");

            if (password1->second != password2->second) {
                throw PasswordMismatchException();
            }

            _request.POST.emplace("password", password1->second);
            _request.POST.erase(password1);
            _request.POST.erase(password2);

            User::create(_request.POST);
        } else if (formType->second != "sign_in") {
            throw NoFormParameterException();
        }

        _request.POST.erase(formType);

        _request.OPTIONS.emplace("username", _request.POST["username"]);

        auto user = authenticate();
        _renderedPage = _renderer.loginSuccess(_request);
    }
};


#endif //MAIN_DELETEUSERCOMMAND_H
