//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEFIELD_H
#define ORM_DATEFIELD_H

#include "BaseField.h"

struct Date : public BaseData {
    unsigned short year = 0;
    unsigned char month = 0;
    unsigned char day = 0;
};

class DateField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return std::to_string(data.day) + '-' + std::to_string(data.month) + '-' + std::to_string(data.year);
    }

protected:
    Date data;

    friend class DateValidator;
};

#endif //ORM_DATEFIELD_H
