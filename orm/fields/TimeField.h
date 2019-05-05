//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef ORM_TIMEFIELD_H
#define ORM_TIMEFIELD_H

#include "BaseField.h"

class TimeField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {

    }

protected:
    unsigned char hour = 0;
    unsigned char minute = 0;
    unsigned char second = 0;

    friend class TimeValidator;
};

#endif //ORM_TIMEFIELD_H
