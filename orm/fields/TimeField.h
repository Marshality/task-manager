//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef ORM_TIMEFIELD_H
#define ORM_TIMEFIELD_H

#include "BaseField.h"

struct Time : BaseData {
    unsigned char hour = 0;
    unsigned char minute = 0;
    unsigned char second = 0;
};

class TimeField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

    std::string stringify() const override {
        return std::to_string(data.hour) + ':' + std::to_string(data.minute) + ':' + std::to_string(data.second);
    }

protected:
    Time data;

    friend class TimeValidator;
};

#endif //ORM_TIMEFIELD_H
