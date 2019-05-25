//
// Created by Marseille Gulaya ft. Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_BASECOMMAND_H
#define MAIN_BASECOMMAND_H

#include "Request.h"
#include "web_template_engine/Renderer.h"


class BaseCommand {
public:
    explicit BaseCommand(Renderer& renderer, Request& request) : _renderer(renderer), _request(request) {}

    virtual void execute() = 0;

    std::string getPage() {
        return _renderedPage;
    }

protected:
    Renderer& _renderer;
    Request& _request;
    std::string _renderedPage;
};


#endif //MAIN_BASECOMMAND_H
