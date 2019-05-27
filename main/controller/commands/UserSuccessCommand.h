//
// Created by Святослав Кряжев on 27.05.2019.
//

#ifndef MAIN_DELETEUSERCOMMAND_H
#define MAIN_DELETEUSERCOMMAND_H

#include "BaseCommand.h"
#include "exceptions/NoFormParameterException.h"


class UserSuccessCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto formType = _request.POST.find("form");

        if (formType == _request.POST.end()) {
            throw NoFormParameterException();
        }

        if (formType->second == "sign_up") {
            _request.POST.erase(formType);
            User::create(_request.POST);
        } else if (formType->second != "sign_in") {
            throw NoFormParameterException();
        }

        _request.OPTIONS.emplace("username", _request.POST["username"]);

        auto user = authenticate();
        _renderedPage = _renderer.loginSuccess(_request);
    }
};


#endif //MAIN_DELETEUSERCOMMAND_H
