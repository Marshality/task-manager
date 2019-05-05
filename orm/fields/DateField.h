//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATEFIELD_H
#define ORM_DATEFIELD_H

#include "BaseField.h"

class DateField : public virtual BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
    }

protected:
    unsigned short year = 0;
    unsigned char month = 0;
    unsigned char day = 0;

    friend class DateValidator;
};

#endif //ORM_DATEFIELD_H
