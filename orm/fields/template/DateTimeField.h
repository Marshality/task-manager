//
// Created by Святослав Кряжев on 04.05.2019.
//

#ifndef ORM_DATETIMEFIELD_H
#define ORM_DATETIMEFIELD_H

#include "DateField.h"
#include "TimeField.h"

struct DateTime : public Date, public Time {

};

class DateTimeField : public Field<DateTime> {
    using Base = Field<DateTime>;

public:
    using Base::Base;
    using Base::operator=;
};

#endif //ORM_DATETIMEFIELD_H
