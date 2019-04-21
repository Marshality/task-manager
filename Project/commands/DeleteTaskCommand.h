//
// Created by Marseille Gulaya on 2019-04-21.
//

#ifndef PROJECT_DELETETASKCOMMAND_H
#define PROJECT_DELETETASKCOMMAND_H

#include "BaseCommand.h"
#include <string>
#include "../Task.h"

class DeleteTaskCommand : public BaseCommand {
public:
    explicit DeleteTaskCommand(std::string& _id) : id(_id) {}

    void execute() override;

private:
    std::string& id;
};

void DeleteTaskCommand::execute() {
    Task::objects()->remove(id);
}

#endif //PROJECT_DELETETASKCOMMAND_H
