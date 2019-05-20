//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_BASEOBJECT_H
#define MAIN_BASEOBJECT_H

#include "ResultSetCompose.h"


class BaseObject : public ResultSetCompose {
public:
    BaseObject(std::shared_ptr<ResultSet> _set, int _index) : ResultSetCompose(std::move(_set)), index(_index) {}

protected:
    int index;

    friend class BaseSet;
};

#endif //MAIN_BASEOBJECT_H
