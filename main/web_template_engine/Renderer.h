//
// Created by Юлия Плаксина on 2019-05-19.
//
#include <mstch/mstch.hpp>
#include "FileToStringConverter.h"

#include "task/Task.h"
#include "project/Project.h"
#include "user/User.h"

class Renderer {
public:

    std::string MainPage() {
        return base(mainPage(), "Главная");
    }

    std::string ProjectListPage(std::shared_ptr<Set<Project>> projects) {
        return base(projectListPage(projects), "Список проектов");
    }

    std::string ProjectPage(std::shared_ptr<Project> project) {
        return base(projectPage(project), "Проект");
    }

    std::string TaskPage(std::shared_ptr<Task> task) {
        return base(taskPage(task), "Задача");
    }

private:
    FileToStringConverter path = FileToStringConverter("templates/");

    std::string base(std::string body, std::string pageTitle);

    std::string mainPage();
    std::string projectListPage(std::shared_ptr<Set<Project>> projects);
    std::string projectPage(std::shared_ptr<Project> project);
    std::string taskPage(std::shared_ptr<Task> task);

};