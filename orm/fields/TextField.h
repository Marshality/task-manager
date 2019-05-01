//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_TEXTFIELD_H
#define ORM_TEXTFIELD_H

#include "BaseField.h"

class TextField : public BaseField {
public:
    inline TextField& operator=(const std::string& _data) override {
        accept(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return data;
    }

protected:
    std::string data;

    void accept(const std::string& string) override {
        data = string;
    }
};

#endif //ORM_TEXTFIELD_H
