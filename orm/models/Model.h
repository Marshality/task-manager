//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_BASEOBJECT_H
#define ORM_BASEOBJECT_H

#include "Manager.h"


template <typename Object>
class Model {
public:
    void save() {
        auto object = static_cast<Object&>(*this);
        objects.save(object);
    }

protected:
    // Allowing this class construction only as a compound of derived class
    Model() = default;

    // Binding derived class with its default manager
    static Manager<Object> objects;
};

template <typename Object>
Manager<Object> Model<Object>::objects = {};


#endif //ORM_BASEOBJECT_H
