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

    std::string mainPage() {
        return base(renderMain(), "Главная");
    }

    std::string projectListPage(std::shared_ptr<Set<Project>> projects) {
        return base(renderProjectList(projects), "Список проектов");
    }

    std::string projectPage(std::shared_ptr<Project> project) {
        return base(renderProject(project), "Проект");
    }

    std::string taskPage(std::shared_ptr<Task> task) {
        return base(renderTask(task), "Задача");
    }

private:
    FileToStringConverter path = FileToStringConverter("web_template_engine/templates/");

    std::string base(std::string body, std::string pageTitle);

    std::string renderMain();
    std::string renderProjectList(std::shared_ptr<Set<Project>> projects);
    std::string renderProject(std::shared_ptr<Project> project);
    std::string renderTask(std::shared_ptr<Task> task);

};