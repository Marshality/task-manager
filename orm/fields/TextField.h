//
// Created by Святослав Кряжев on 25.04.2019.
//

#ifndef ORM_TEXTFIELD_H
#define ORM_TEXTFIELD_H

#include "CharField.h"

class TextField : public virtual CharField {
public:
    using CharField::BaseField;
    using BaseField::operator=;

protected:
    friend class TextValidator;
};

#endif //ORM_TEXTFIELD_H
