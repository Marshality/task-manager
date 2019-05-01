//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATETIMEFIELD_H
#define ORM_DATETIMEFIELD_H

#include "DateField.h"

class DateTimeField : public DateField {
public:

private:
    unsigned char hour = 0;
    unsigned char minute = 0;
    unsigned char second = 0;
};

#endif //ORM_DATETIMEFIELD_H
