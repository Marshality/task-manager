//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>
#include "BaseField.h"

class IntegerField : public BaseField {
public:
    explicit IntegerField(BaseValidator* _validator) : BaseField::BaseField(_validator) {}

    inline IntegerField& operator=(long long _data) {
        data = _data;
        return *this;
    }

    inline IntegerField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return std::to_string(data);
    }

private:
    long long data = 0;

    void pass(const std::string& string) override {
        validator->pass(string, this);
    }

    friend class IntegerValidator;
};

#endif //ORM_INTEGERFIELD_H
