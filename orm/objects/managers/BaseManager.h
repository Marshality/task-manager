//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_IMANAGER_H
#define ORM_IMANAGER_H

#include "Meta.h"

class BaseManager {
public:
    BaseManager();
    ~BaseManager() = default;
protected:
    Meta metaInfo;

    friend class ManagerPool;
};


#endif //ORM_IMANAGER_H
