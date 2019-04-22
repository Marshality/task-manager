//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_INTEGERVALIDATOR_H
#define ORM_INTEGERVALIDATOR_H

#include "BaseValidator.h"

class IntegerValidator : public BaseValidator {
public:
    bool isValid(const std::string& string) override;

    long long getCache() const;

private:
    long long cache;
};

#endif //ORM_INTEGERVALIDATOR_H
