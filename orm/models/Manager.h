//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <string>
#include "Meta.h"

template <typename Object>
class Model;

template <typename Object>
class Manager {
public:
    Manager();
    ~Manager();

    Object get(const std::string& options) const;

private:
    void save(Model<Object>& model) const;
};


#endif //ORM_MANAGER_H
