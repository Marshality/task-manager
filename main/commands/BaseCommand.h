//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_BASECOMMAND_H
#define MAIN_BASECOMMAND_H

#include "Request.h"


class BaseCommand {
public:
    explicit BaseCommand(Request& _request) : request(_request) {}

    virtual void execute() const = 0;

protected:
    Request& request;
};


#endif //MAIN_BASECOMMAND_H
