//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <string>

template <typename Object>
class Model;

template <typename Object>
class Manager {
public:
    Object get(const std::string& options) const;

private:
    void save(Model<Object>& model) const;

    friend class Model<Object>;
};

#endif //ORM_MANAGER_H
