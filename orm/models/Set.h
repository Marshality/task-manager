//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef ORM_SET_H
#define ORM_SET_H

#include <vector>

template <typename Object>
class Set {
public:
    std::vector<Object>& getObjects() const {
        return array;
    }

    void save() const {
        for (auto& object : array) {
            object.save();
        }
    }

private:
    std::vector<Object> array;
};

#endif //ORM_SET_H
