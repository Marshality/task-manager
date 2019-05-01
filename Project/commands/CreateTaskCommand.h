//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_CREATETASKCMD_H
#define PROJECT_CREATETASKCMD_H

#include "BaseCommand.h"
#include <unordered_map>
#include "../Task.h"
#include "exceptions/FieldIsMissedException.h"

class CreateTaskCommand : public BaseCommand {
public:
    explicit CreateTaskCommand(std::unordered_map<std::string, std::string>& _data) : data(_data) {}

    void execute() override;

private:
    std::unordered_map<std::string, std::string>& data;
};

void CreateTaskCommand::execute() {
    Task task;

    auto it = data.find("title"); // required minimum for task creation
    if (it == data.end()) {
        // ... message to http-server
        throw FieldIsMissedException();
    }

    task.title = it->second;

    it = data.find("description");
    if (it != data.end()) {
        task.description = it->second;
    }

    it = data.find("assignee");
    if (it != data.end()) {
        task.assignee = it->second;
    }

    task.save();
}

#endif //PROJECT_CREATETASKCMD_H
