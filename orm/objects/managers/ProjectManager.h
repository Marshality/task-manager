//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_PROJECTMANAGER_H
#define ORM_PROJECTMANAGER_H

#include <string>
#include "BaseManager.h"

class Project;

class ProjectManager : public BaseManager {
public:
    Project get(std::string&& options) const;

private:
    ProjectManager() = default;
    ~ProjectManager() = default;

    friend class Project;
};


#endif //ORM_PROJECTMANAGER_H
