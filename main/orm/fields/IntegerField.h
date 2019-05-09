//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <iostream>
#include <string>
#include "BaseField.h"


struct Integer : public BaseData {
    Integer() = default;
    Integer(int val) : value(val) {}
    long long value = 0;
};

class IntegerField : public BaseField {
public:
    struct Options {
        int min_value;
        int max_value;
    };
public:
    using BaseField::BaseField;
    using BaseField::operator=;


//    static IntegerField set(Options options) {
//        return IntegerField(nullptr);
//    }
//
//    static IntegerField operator() (Options options) {
//        return IntegerField(nullptr);
//    }

    explicit IntegerField(Options options) : data(7), BaseField(nullptr) {
        std::cout << "lol" << std::endl;
    }

    inline IntegerField& operator=(long long _data) {
        data.value = _data;
        return *this;
    }

    std::string stringify() const override {
        return std::to_string(data.value);
    }

private:
    Integer data;

    friend class IntegerValidator;
};

#endif //ORM_INTEGERFIELD_H
