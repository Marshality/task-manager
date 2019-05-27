//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_USER_H
#define MAIN_USER_H

#include "StorageAccess.h"
#include "BaseObject.h"
#include "Set.h"


class Project;
class Task;

class User : public BaseObject, public StorageAccess<User> {
public:
    using BaseObject::BaseObject;

    // Direct fields
    const char* id() const;
    const char* username() const;
    const char* password() const;
    const char* name() const;
    const char* surname() const;

    // Relative fields
    std::shared_ptr<Set<Project>> projects();
    std::shared_ptr<Set<Task>> tasks();

private:
    std::shared_ptr<Set<Project>> projectsInstance;
    std::shared_ptr<Set<Task>> tasksInstance;
};


#endif //MAIN_USER_H
