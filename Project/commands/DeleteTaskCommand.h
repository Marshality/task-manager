//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_DELETETASKCOMMAND_H
#define PROJECT_DELETETASKCOMMAND_H

#include "BaseCommand.h"
#include <unordered_map>
#include "../Task.h"
#include "exceptions/IdIsNotFoundException.h"

class DeleteTaskCommand : public BaseCommand {
public:
    explicit DeleteTaskCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void DeleteTaskCommand::execute() {
    auto it = data.find("id");

    if (it == data.end()) {
        // ... message to http-server
        throw IdIsNotFoundException();
    }

    Task::objects()->remove(it->second);
}

#endif //PROJECT_DELETETASKCOMMAND_H
