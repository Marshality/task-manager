//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>

#include "validators/IntegerValidator.h"
#include "BaseField.h"

class IntegerField : public BaseField {
public:
    inline IntegerField& operator=(long long _data) {
        data = _data;
        return *this;
    }

    inline IntegerField& operator=(const std::string& _data) override {
        accept(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return std::to_string(data);
    }

private:
    long long data = 0;

    void accept(const std::string& string) override {
        if (string.empty() && !std::isdigit(string[0]) && string[0] != '-' && string[0] != '+') {
            throw "Not an integer";
        }

        char* endPtr;
        auto temp = std::strtoll(string.c_str(), &endPtr, 10);

        if (*endPtr != 0) {
            throw "Met unacceptable symbols";
        }

        data = temp;
    }
};

#endif //ORM_INTEGERFIELD_H
