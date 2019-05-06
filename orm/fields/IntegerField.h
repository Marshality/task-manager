//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERFIELD_H
#define ORM_INTEGERFIELD_H

#include <string>
#include "BaseField.h"

struct Integer : public BaseData {
    long long value = 0;
};

class IntegerField : public BaseField {
public:
<<<<<<< HEAD
    using BaseField::BaseField;
    using BaseField::operator=;
=======
    explicit IntegerField(BaseValidator* _validator) : BaseField::BaseField(_validator) {}
>>>>>>> main_logic

    inline IntegerField& operator=(long long _data) {
        data = _data;
        return *this;
    }

<<<<<<< HEAD
    std::string stringify() const override {
=======
    inline IntegerField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

    inline std::string stringify() const override {
>>>>>>> main_logic
        return std::to_string(data);
    }

private:
<<<<<<< HEAD
    Integer data;
=======
    long long data = 0;

    void pass(const std::string& string) override {
        validator->pass(string, this);
    }
>>>>>>> main_logic

    friend class IntegerValidator;
};

#endif //ORM_INTEGERFIELD_H
