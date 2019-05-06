//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_CREATEPROJECTCOMMAND_H
#define PROJECT_CREATEPROJECTCOMMAND_H

#include "BaseCommand.h"
#include <unordered_map>
#include "../Project.h"
#include "./exceptions/FieldIsMissedException.h"

class CreateProjectCommand : public BaseCommand {
public:
    explicit CreateProjectCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void CreateProjectCommand::execute() {
    Project project;

    auto it1 = data.find("title");
    auto it2 = data.find("description");

    if (it1 == data.end() || it2 == data.end()) { // required minimum for main_logic creation
        // ... message to http-server
        throw FieldIsMissedException();
    }

    // other fields
    // ...

    project.save();
}

#endif //PROJECT_CREATEPROJECTCOMMAND_H
