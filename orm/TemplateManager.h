//
// Created by Святослав Кряжев on 22.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <iostream>

template <typename Object>
class Manager {
public:
    void print() { Object::print(); }
};

template <typename Object>
class BaseObject {
public:
    static Manager<Object> objects() { return Manager<Object>(); }
};

class User : public BaseObject<User> {
public:
    static void print() { std::cout << "User" << std::endl; }
};

class Project : public BaseObject<Project> {
public:
    static void print() { std::cout << "Project" << std::endl; }
};


#endif //ORM_MANAGER_H
