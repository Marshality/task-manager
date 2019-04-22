//
// Created by Святослав Кряжев on 21.04.2019.
//

#include "Project.h"

static ProjectManager* projectManagerInstance = nullptr;

ProjectManager* Project::objects() {
    if (!projectManagerInstance) {
        projectManagerInstance = new ProjectManager();
    }

    return projectManagerInstance;
}