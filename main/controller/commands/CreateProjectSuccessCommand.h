//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_DELETEPROJECTCOMMAND_H
#define MAIN_DELETEPROJECTCOMMAND_H

#include "BaseCommand.h"
#include "project/Project.h"


class CreateProjectSuccessCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto user = authenticate();

        _request.POST.emplace("owner_id", user->id());
        Project::create(_request.POST);
        auto project = Project::getOne(_request.POST);

        _renderedPage = _renderer.addProjectSuccess(_request, project);
    }
};


#endif //MAIN_DELETEPROJECTCOMMAND_H
