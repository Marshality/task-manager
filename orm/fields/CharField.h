//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include "TextField.h"

class CharField : public TextField {
public:
    CharField(BaseValidator* _validator) : TextField::TextField(_validator) {}

    inline CharField& operator=(const std::string& _data) override {
        pass(_data);
        return *this;
    }

private:
    inline void pass(const std::string& string) override {
        validator->pass(string, this);
    }

    friend class CharValidator;
};

#endif //ORM_CHARFIELD_H
