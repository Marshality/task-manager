//
// Created by Святослав Кряжев on 25.05.2019.
//

#ifndef MAIN_GETPROJECTCOMMAND_H
#define MAIN_GETPROJECTCOMMAND_H

#include "BaseCommand.h"
#include "project/Project.h"


class GetProjectCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto project = Project::getOne(request.GET);

        renderedPage = renderer.projectPage(project);
    }
};

#endif //MAIN_GETPROJECTCOMMAND_H
