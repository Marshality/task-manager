//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_RESULTSETCOMPOSE_H
#define MAIN_RESULTSETCOMPOSE_H

#include "ResultSet.h"


class ResultSetCompose {
protected:
    explicit ResultSetCompose(const std::shared_ptr<ResultSet>& _set) : set(_set) {}

    const std::shared_ptr<ResultSet> set;
};


#endif //MAIN_RESULTSETCOMPOSE_H
