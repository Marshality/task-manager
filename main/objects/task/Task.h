//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_TASK_H
#define MAIN_TASK_H

#include "BaseObject.h"
#include "StorageQuickAccess.h"
#include "Set.h"


class Project;
class User;

class Task : public BaseObject, public StorageQuickAccess<Task> {
public:
    using BaseObject::BaseObject;

    // Direct fields
    const char* id() const;
    const char* user_id() const;
    const char* project_id() const;
    const char* title() const;
    const char* description() const;
    const char* creation_date() const;
    const char* deadline() const;

    // Relative fields
    std::shared_ptr<User> user();
    std::shared_ptr<Project> project();

private:
    std::shared_ptr<Project> projectInstance = nullptr;
    std::shared_ptr<User> userInstance = nullptr;
};


#endif //MAIN_TASK_H
