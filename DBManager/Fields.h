//
// Created by Святослав Кряжев on 15.04.2019.
//

#ifndef POSTGRESQL_ORM_FIELDS_H
#define POSTGRESQL_ORM_FIELDS_H

#include <string>

class Field {
    virtual bool validate(std::string string) = 0;
};

class CharField : public Field {
    bool validate(std::string string) override {
        for (auto c : string) {
            // Validating
        }

        return true;
    }
};

class IntegerField : public Field {
    bool validate(std::string string) override {}
};

class TextField : public Field {
    bool validate(std::string string) override {}
};

class DateField : public Field {
    bool validate(std::string string) override {}
};

#endif //POSTGRESQL_ORM_FIELDS_H
