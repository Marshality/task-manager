//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_EDITPROJECTCOMMAND_H
#define PROJECT_EDITPROJECTCOMMAND_H

#include "BaseCommand.h"
#include <unordered_map>
#include "../Project.h"
#include "exceptions/FieldIsMissedException.h"

class EditProjectCommand : public BaseCommand {
public:
    explicit EditProjectCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void EditProjectCommand::execute() {
    auto it = data.find("id");

    if (it == data.end()) {
        // message to http-server
        throw FieldIsMissedException();
    }

    std::string options;
    for (auto& iterator : data) {
        options.append(iterator.first);
        options.append("=");
        options.append(iterator.second);
        options.append(" ");
    }

    Project::objects()->update(options);
}


#endif //PROJECT_EDITPROJECTCOMMAND_H
