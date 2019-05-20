//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_BASESET_H
#define MAIN_BASESET_H

#include <functional>
#include "ResultSetCompose.h"
#include "BaseObject.h"


class BaseSet : public ResultSetCompose {
public:
    explicit BaseSet(const std::shared_ptr<ResultSet>& _set) : ResultSetCompose(_set) {}

protected:
    void setIndexToObject(BaseObject& object, int _index) const {
        object.index = _index;
    }
};

#endif //MAIN_BASESET_H
