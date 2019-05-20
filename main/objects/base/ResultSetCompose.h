//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_RESULTSETCOMPOSE_H
#define MAIN_RESULTSETCOMPOSE_H

#include <memory>
#include "ResultSet.h"


class ResultSetCompose {
protected:
    explicit ResultSetCompose(std::shared_ptr<ResultSet> _set) : set(std::move(_set)) {}

    const std::shared_ptr<ResultSet> set;
};


#endif //MAIN_RESULTSETCOMPOSE_H
