//
// Created by Святослав Кряжев on 25.05.2019.
//

#ifndef MAIN_GETPROJECTLISTPAGE_H
#define MAIN_GETPROJECTLISTPAGE_H

#include "BaseCommand.h"
#include "project/Project.h"


class GetProjectListCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto user = authenticate();

        auto projects = user->projects();

        _renderedPage = _renderer.projectListPage(_request, projects);
    }
};


#endif //MAIN_GETPROJECTLISTPAGE_H
