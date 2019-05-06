//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

<<<<<<< HEAD
#include "BaseField.h"
=======
#include "TextField.h"
>>>>>>> main_logic

struct Char {
    std::string data;
};

class CharField : public BaseField {
public:
<<<<<<< HEAD
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return data;
    }

private:
    Char data;
=======
    CharField(BaseValidator* _validator) : TextField::TextField(_validator) {}

    inline CharField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

private:
    inline void pass(const std::string& string) override {
        validator->pass(string, this);
    }
>>>>>>> main_logic

    friend class CharValidator;
};

#endif //ORM_CHARFIELD_H
