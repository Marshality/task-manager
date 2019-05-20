//
// Created by Святослав Кряжев on 19.05.2019.
//

#ifndef MAIN_USER_H
#define MAIN_USER_H

#include "StorageQuickAccess.h"
#include "BaseObject.h"
#include "Set.h"


class ProjectSet;
class TaskSet;

class User : public BaseObject, public StorageQuickAccess<User> {
public:
    using BaseObject::BaseObject;

    // Direct fields
    const char* id() const;
    const char* name() const;
    const char* surname() const;
    const char* birth_date() const;
    const char* avatar() const;

    // Relative fields
    std::shared_ptr<ProjectSet> projects();
    std::shared_ptr<TaskSet> tasks();

private:
    std::shared_ptr<ProjectSet> projectsInstance;
    std::shared_ptr<TaskSet> tasksInstance;
};


#endif //MAIN_USER_H
