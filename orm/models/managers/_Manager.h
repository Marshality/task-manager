//
// Created by Святослав Кряжев on 26.04.2019.
//

#include "Manager.h"
#include "Model.h"

template <typename Object>
void Manager<Object>::save(Model<Object>& model) const {
    auto& object = static_cast<Object&>(model);
    //object.print();
}