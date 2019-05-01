//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_BASEOBJECT_H
#define ORM_BASEOBJECT_H

#include "Manager.h"

template <typename Object>
class Model {
public:
    void save();

protected:
    // Allowing this class construction only as a compound of derived class
    Model() = default;

    // Binding derived class with its default manager
    static constexpr Manager<Object> objects;
};

template <typename Object>
void Model<Object>::save() {
    objects.save(*this);
}

struct Task : public Model<Task> {

};

#endif //ORM_BASEOBJECT_H
