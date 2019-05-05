//
// Created by Святослав Кряжев on 03.05.2019.
//

#ifndef ORM_DATEFIELD_H
#define ORM_DATEFIELD_H

#include "Field.h"

struct Date {
    unsigned short year;
    unsigned char month;
    unsigned char day;

    explicit operator std::string() const {
        auto string = formDate(day, 2);
        string += "-";
        string += formDate(month, 2);
        string += "-";
        string += formDate(year, 4);

        return string;
    }

private:
    std::string formDate(int date, int n) const {
        auto _date = std::to_string(date);
        int diff = n - (int) _date.length();

        if (!diff) {
            return _date;
        }

        std::string zeros;
        for (int i = 0; i < diff; ++i) {
            zeros.append("0");
        }

        return zeros + _date;
    }
};

class DateField : public Field<Date> {
    using Base = Field<Date>;

public:
    using Base::Base;
    using Base::operator=;
};

#endif //ORM_DATEFIELD_H
