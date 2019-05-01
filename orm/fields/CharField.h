//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include "TextField.h"
#include "CharValidator.h"

class CharField : public TextField {
public:
    CharField(unsigned long _maxLength = 128) : maxLength(_maxLength) {}

    inline CharField& operator=(const std::string& _data) override {
        accept(_data);
        return *this;
    }

private:
    unsigned long maxLength;

    void accept(const std::string& string) override {
        if (string.length() > maxLength) {
            throw "String length exceeds max possible";
        }

        data = string;
    }
};

#endif //ORM_CHARFIELD_H
