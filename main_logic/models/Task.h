//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_LOGIC_TASK_H
#define MAIN_LOGIC_TASK_H

#include "Model.h"

class Task : public Model {
    enum Fields {
        ID,
        TITLE,
        DESCRIPTION,
        USER_ID,
        PROJECT_ID,
        CREATION_DATE,
        DEADLINE
    };

public:
    Task() {
        data.reserve(7);
    }

    std::string& id() {
        return data.at(ID);
    }

    std::string& title() {
        return data.at(TITLE);
    }

    std::string& description() {
        return data.at(DESCRIPTION);
    }

private:

};

#endif //MAIN_LOGIC_TASK_H
