//
// Created by Marseille Gulaya ft. Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_CREATEPROJECTCOMMAND_H
#define MAIN_CREATEPROJECTCOMMAND_H

#include "BaseCommand.h"
#include "project/Project.h"


class CreateProjectCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        auto user = authenticate();
        _renderedPage = _renderer.addProject(_request);
    }
};


#endif //MAIN_CREATEPROJECTCOMMAND_H
