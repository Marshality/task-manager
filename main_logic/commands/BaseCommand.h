//
// Created by Marseille Gulaya on 2019-04-08.
//

#ifndef PROJECT_BASECOMMAND_H
#define PROJECT_BASECOMMAND_H


class BaseCommand {
public:
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;
};


#endif //PROJECT_BASECOMMAND_H
