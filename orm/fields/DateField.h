//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEFIELD_H
#define ORM_DATEFIELD_H

#include "BaseField.h"

<<<<<<< HEAD
struct Date : public BaseData {
=======
class DateField : public BaseField {
public:
    inline DateField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

    inline std::string stringify() const override {
        return std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
    }

protected:
>>>>>>> main_logic
    unsigned short year = 0;
    unsigned char month = 0;
    unsigned char day = 0;
};

<<<<<<< HEAD
class DateField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return std::to_string(data.day) + '-' + std::to_string(data.month) + '-' + std::to_string(data.year);
    }

protected:
    Date data;

=======
    inline void pass(const std::string& string) override {
        validator->pass(string, this);
    }

>>>>>>> main_logic
    friend class DateValidator;
};

#endif //ORM_DATEFIELD_H
