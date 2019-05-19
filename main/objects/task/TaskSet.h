//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_TASKSET_H
#define MAIN_TASKSET_H

#include "BaseSet.h"
#include "Task.h"


class TaskSet : public BaseSet {
    using handlerFunc = std::function<void (Task&)>;

public:
    using BaseSet::BaseSet;

    void bypass(const handlerFunc& handle) const {
        int count = set->getObjectsCount();

        Task task(set, 0);
        handle(task);

        for (int i = 1; i < count; ++i) {
            setIndexToObject(task, i);
            handle(task);
        }
    }
};


#endif //MAIN_TASKSET_H
