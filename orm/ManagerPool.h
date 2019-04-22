//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_MANAGERPOOL_H
#define ORM_MANAGERPOOL_H

#include <vector>
#include "BaseManager.h"

class ManagerPool {
private:
    ManagerPool() = default;
    ~ManagerPool() = default;

    static ManagerPool& getInstance();
    void push(BaseManager* manager);

    std::vector<std::unique_ptr<BaseManager>> pool;

    friend class BaseManager::BaseManager;
};


// Implementation

ManagerPool& ManagerPool::getInstance() {
    // Lazy initialization
    static ManagerPool instance;

    return instance;
}

void ManagerPool::push(BaseManager* manager) {
    pool.push_back(std::unique_ptr<BaseManager>(manager));
}

#endif //ORM_MANAGERPOOL_H
