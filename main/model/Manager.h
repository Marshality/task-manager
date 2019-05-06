//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_MANAGER_H
#define MAIN_MANAGER_H

#include "Types.h"


template <typename Object>
class Model;

template <typename Object>
class Meta;

template <typename Object>
class Manager {
public:
    Manager() {}
    ~Manager() = default;

    Object get(const map& kwargs) const;
    void save(Model<Object>& model) const;

private:
    Meta<Object> meta;

};


#endif //MAIN_MANAGER_H
