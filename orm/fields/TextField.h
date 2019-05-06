//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_TEXTFIELD_H
#define ORM_TEXTFIELD_H

#include "BaseField.h"

class TextField : public BaseField {
public:
    using BaseField::BaseField;
    using BaseField::operator=;

protected:


    friend class TextValidator;
};

#endif //ORM_TEXTFIELD_H
