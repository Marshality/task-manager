//
// Created by Святослав Кряжев on 21.04.2019.
//

#include "BaseManager.h"
#include "ManagerPool.h"

BaseManager::BaseManager()
{
    ManagerPool::getInstance().push(this);
}