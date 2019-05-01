//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_TEXTFIELD_H
#define ORM_TEXTFIELD_H

#include "BaseField.h"

class TextField : public BaseField {
public:
    explicit TextField(BaseValidator* _validator) : BaseField::BaseField(_validator) {}

    inline TextField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return data;
    }

protected:
    std::string data;

    void pass(const std::string& string) override {
        validator->pass(string, this);
    }

    friend class TextValidator;
};

#endif //ORM_TEXTFIELD_H
