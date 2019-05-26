//
// Created by Юлия Плаксина on 2019-05-19.
//
#include <mstch/mstch.hpp>
#include "FileToStringConverter.h"

#include "task/Task.h"
#include "project/Project.h"
#include "user/User.h"

#include "Request.h"

class Renderer {
public:
    std::string mainPage(Request& request) {
        return base(renderMain(), "Главная");
    }

    std::string projectListPage(Request& _request, std::shared_ptr<Set<Project>> projects) {
        return base(renderProjectList(_request, projects), "Список проектов");
    }

    std::string projectPage(Request& _request, std::shared_ptr<Project> project) {
        return base(renderProject(_request, project), "Проект");
    }

    std::string taskPage(Request& _request, std::shared_ptr<Task> task) {
        return base(renderTask(_request, task), "Задача");
    }

    std::string addTask(Request& _request, std::shared_ptr<Set<User>> users) {
        return base(renderAddTask(_request, users), "Добавление задачи");
    }

    std::string addProject(Request& _request) {
        return base(renderAddProject(_request), "Добавление проекта");
    }

    std::string loginSuccess(Request& _request) {
        return base(renderLoginSuccess(_request), "Успешно");
    }

    std::string addProjectSuccess(Request& _request, std::shared_ptr<Project> project) {
        return base(renderAddProjectSuccess(_request, project), "Успешно");
    }

    std::string addTaskSuccess(Request& _request) {
        return base(renderAddTaskSuccess(_request), "Успешно");
    }

private:
    FileToStringConverter path = FileToStringConverter("../web_template_engine/templates/");

    std::string base(std::string body, std::string pageTitle);

    std::string renderMain();
    std::string renderProjectList(Request& request, std::shared_ptr<Set<Project>> projects);
    std::string renderProject(Request& request, std::shared_ptr<Project> project);
    std::string renderTask(Request& request, std::shared_ptr<Task> task);
    std::string renderAddTask(Request& request, std::shared_ptr<Set<User>> users);
    std::string renderAddProject(Request& request);
    std::string renderLoginSuccess(Request& request);
    std::string renderAddProjectSuccess(Request& request, std::shared_ptr<Project> project);
    std::string renderAddTaskSuccess(Request& request);
};