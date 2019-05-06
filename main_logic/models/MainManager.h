//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef MAIN_LOGIC_OBJECTMANAGER_H
#define MAIN_LOGIC_OBJECTMANAGER_H

#include <vector>
#include "Connection.h"
#include "ObjectManager.h"

class MainManager {
public:
    MainManager();

    std::vector<Object> get(ObjectType type, map& kwargs) const;

    void update(ObjectType, map& kwargs) const;

    void save(Object& object) const;

    void remove(ObjectType, map& kwargs) const;

protected:
    Connection connection;

    std::unordered_map<ObjectType, set> meta;
};

#endif //MAIN_LOGIC_OBJECTMANAGER_H
