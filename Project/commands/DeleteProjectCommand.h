//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_DELETEPROJECTCOMMAND_H
#define PROJECT_DELETEPROJECTCOMMAND_H

#include "BaseCommand.h"
#include <string>
#include "../Project.h"
#include "exceptions/IdIsNotFoundException.h"

class DeleteProjectCommand : public BaseCommand {
public:
    explicit DeleteProjectCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void DeleteProjectCommand::execute() {
    auto it = data.find("id");

    if (it == data.end()) {
        // ... message to http-server
        throw IdIsNotFoundException();
    }

    Project::objects()->remove(it->second);
}

#endif //PROJECT_DELETEPROJECTCOMMAND_H
