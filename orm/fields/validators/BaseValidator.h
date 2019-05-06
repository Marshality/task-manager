//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_BASEVALIDATOR_H
#define ORM_BASEVALIDATOR_H

#include <string>

class BaseField;

class BaseValidator {
public:
<<<<<<< HEAD
    virtual ~BaseValidator() = default;

    // Polymorphic that validates input and validated passes data into field (if sent)
    virtual void pass(const std::string& string, BaseField* field) const = 0;

    void check(const std::string& string) const {
        pass(string, nullptr);
    }
=======
    // Polymorphic that validates input and validated passes data into field (if sent)
    virtual void pass(const std::string& string, BaseField* field) = 0;
>>>>>>> main_logic
};

#endif //ORM_BASEVALIDATOR_H
