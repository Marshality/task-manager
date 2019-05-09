//
// Created by Святослав Кряжев on 28.04.2019.
//

#ifndef ORM_DATETIMEFIELD_H
#define ORM_DATETIMEFIELD_H

#include "DateField.h"
#include "TimeField.h"

class DateTimeField : public BaseField {
public:
    using DateField::BaseField::operator=;

    explicit DateTimeField(BaseValidator* _validator) :
        BaseField(_validator),
        dateField(_validator),
        timeField(_validator) {}


    std::string stringify() const override {
        return dateField.stringify() + ' ' + timeField.stringify();
    }

private:
    DateField dateField;
    TimeField timeField;

    friend class DateTimeValidator;
};

#endif //ORM_DATETIMEFIELD_H
