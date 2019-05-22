//
// Created by Marseille Gulaya ft. Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_BASECOMMAND_H
#define MAIN_BASECOMMAND_H

#include "Request.h"
#include "web_template_engine/Renderer.h"


class BaseCommand {
public:
    explicit BaseCommand(Renderer& _renderer, Request& _request) : renderer(_renderer), request(_request) {}

    virtual void execute() = 0;

    std::string getPage() {
        return renderedPage;
    }

protected:
    Renderer& renderer;
    Request& request;
    std::string renderedPage;
};


#endif //MAIN_BASECOMMAND_H
