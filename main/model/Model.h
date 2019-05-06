//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_MODEL_H
#define MAIN_MODEL_H

#include "Manager.h"


template <typename Object>
class Model {
public:
    void save() {
        objects.save(*this);
    }

protected:
    using field = std::string;

    // Allowing this class construction only as a compound of derived class
    Model() = default;

    // Binding derived class with its default manager
    static Manager<Object> objects;
};

template <typename Object>
Manager<Object> Model<Object>::objects = {};


#endif //MAIN_MODEL_H
