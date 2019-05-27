//
// Created by Святослав Кряжев on 25.05.2019.
//

#ifndef MAIN_INDEXCOMMAND_H
#define MAIN_INDEXCOMMAND_H

#include "BaseCommand.h"


class IndexCommand : public BaseCommand {
public:
    using BaseCommand::BaseCommand;

    void execute() override {
        _renderedPage = _renderer.mainPage(_request);
    }
};


#endif //MAIN_INDEXCOMMAND_H
