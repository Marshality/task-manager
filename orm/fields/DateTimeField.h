//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATETIMEFIELD_H
#define ORM_DATETIMEFIELD_H

#include "DateField.h"
#include "TimeField.h"

class DateTimeField : public DateField, public TimeField {
public:
    using BaseField::operator=;

    explicit DateTimeField(BaseValidator* _validator) :
        BaseField(_validator),
        DateField(_validator),
        TimeField(_validator) {}

    std::string stringify() const override {

    }

private:
    friend class DateTimeValidator;
};

#endif //ORM_DATETIMEFIELD_H
