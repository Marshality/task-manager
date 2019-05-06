//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <string>
#include "Set.h"


template <typename Object>
class Meta;

template <typename Object>
class Manager {
public:
    Manager();

    Object get(const std::string& options) const;
    Set<Object> filter(const std::string& options) const;

    void update(const std::string& options) const;
    void remove(const std::string& options) const;

    void save(Object& model) const;

private:
    Meta<Object> meta;

};


#endif //ORM_MANAGER_H
