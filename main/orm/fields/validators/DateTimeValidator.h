//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef ORM_DATETIMEVALIDATOR_H
#define ORM_DATETIMEVALIDATOR_H

#include "DateValidator.h"
#include "TimeValidator.h"
#include "DateTimeField.h"

class DateTimeValidator : public BaseValidator {
    void pass(const std::string& string, BaseField* _field) const override {
        auto div = string.find(' ');
        auto dateStr = string.substr(0, div);
        auto timeStr = string.substr(div + 1);

        BaseField* dateField = nullptr;
        BaseField* timeField = nullptr;

        if (_field) {
            auto field = dynamic_cast<DateTimeField*>(_field);
            dateField = &field->dateField;
            timeField = &field->timeField;
        }

        dateValidator.pass(dateStr, dateField);
        timeValidator.pass(timeStr, timeField);
    }

private:
    DateValidator dateValidator;
    TimeValidator timeValidator;
};

#endif //ORM_DATETIMEVALIDATOR_H
