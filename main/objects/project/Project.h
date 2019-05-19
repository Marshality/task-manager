//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_PROJECT_H
#define MAIN_PROJECT_H

#include "BaseObject.h"


class User;
class TaskSet;

class Project : public BaseObject {
public:
    using BaseObject::BaseObject;

    // Direct fields
    const char* id() const;
    const char* owner_id() const;
    const char* title() const;
    const char* description() const;
    const char* creation_date() const;

    // Relative fields
    std::shared_ptr<User> owner();
    std::shared_ptr<TaskSet> tasks();

private:
    std::shared_ptr<User> ownerInstance;
    std::shared_ptr<TaskSet> tasksInstance;

};

#endif //MAIN_PROJECT_H
