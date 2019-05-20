//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_SET_H
#define MAIN_SET_H

#include "BaseSet.h"

template <typename Object>
class Set : public BaseSet {
    using handlerFunc = std::function<void (Object&)>;

public:
    using BaseSet::BaseSet;

    void bypass(const handlerFunc& handle) const {
        int count = set->getObjectsCount();

        Object object(set, 0);
        handle(object);

        for (int i = 1; i < count; ++i) {
            setIndexToObject(object, i);
            handle(object);
        }
    }
};


#endif //MAIN_SET_H
