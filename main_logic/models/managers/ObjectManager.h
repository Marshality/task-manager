//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef MAIN_LOGIC_BASEMANAGER_H
#define MAIN_LOGIC_BASEMANAGER_H

#include <vector>

#include "Model.h"

using set = std::vector<std::string>;

class ObjectManager {
public:
    void pass(Object& object) {
        if (object.getFieldsCount() != meta.size()) {
            throw "Number of fields mismatch";
        }

        for (auto& key : meta) {
            object.read(key);
        }
    }

protected:
    set meta;
};

#endif //MAIN_LOGIC_BASEMANAGER_H
