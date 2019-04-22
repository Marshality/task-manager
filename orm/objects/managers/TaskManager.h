//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_TASKMANAGER_H
#define ORM_TASKMANAGER_H

#include <string>
#include "BaseManager.h"

class Task;

class TaskManager : public BaseManager {
public:
    Task get(std::string&& options) const;

private:
    TaskManager() = default;
    ~TaskManager() = default;

    friend class Task;
};

#endif //ORM_TASKMANAGER_H
