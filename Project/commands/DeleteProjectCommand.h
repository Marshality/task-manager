//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_DELETEPROJECTCOMMAND_H
#define PROJECT_DELETEPROJECTCOMMAND_H

#include "BaseCommand.h"
#include <string>
#include "../Project.h"

class DeleteProjectCommand : public BaseCommand {
public:
    explicit DeleteProjectCommand(std::string& _id) : id(_id) {}

    void execute() override;

private:
    std::string& id;
};

void DeleteProjectCommand::execute() {
    Project::objects()->remove(id);
}

#endif //PROJECT_DELETEPROJECTCOMMAND_H
