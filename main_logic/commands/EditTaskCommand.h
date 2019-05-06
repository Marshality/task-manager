//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_EDITTASKCOMMAND_H
#define PROJECT_EDITTASKCOMMAND_H

#include "BaseCommand.h"
#include "../Task.h"
#include <unordered_map>
#include "exceptions/IdIsNotFoundException.h"

class EditTaskCommand : public BaseCommand {
public:
    explicit EditTaskCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void EditTaskCommand::execute() {
    auto it = data.find("id");

    if (it == data.end()) {
        // message to http-server
        throw IdIsNotFoundException();
    }

    std::string options;
    for (auto& iterator : data) {
        options.append(iterator.first);
        options.append("=");
        options.append(iterator.second);
        options.append(" ");
    }

    Task::objects()->update(options);
}


#endif //PROJECT_EDITTASKCOMMAND_H
