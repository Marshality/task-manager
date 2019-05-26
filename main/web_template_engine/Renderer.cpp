//
// Created by Юлия Плаксина on 2019-05-21.
//

#include "Renderer.h"

std::string Renderer::base(std::string body, std::string pageTitle) {

    mstch::map base{
            {"pageTitle", pageTitle},
            {"body", body}
    };

    return mstch::render(path("base.html"), base);
}

std::string Renderer::renderMain() {
    return path("main.html");
}

std::string Renderer::renderProjectList(std::shared_ptr<Set<Project>> projects) {

    mstch::array arr;

    projects->bypass([&arr](Project& project) {
        auto creator = project.owner();

        arr.push_back(
                mstch::map{
                        {"project", mstch::map{
                                {"title", std::string(project.title())},
                                {"description", std::string(project.description())},
                                {"name", std::string(creator->name())},
                                {"surname", std::string(creator->surname())},
                                {"creation_date", std::string(project.creation_date())}
                        }}
                }
        );
    });

    mstch::map context{
            {"projects", arr}
    };

    return mstch::render(path("projectsList.html"), context);
}

std::string Renderer::renderProject(std::shared_ptr<Project> project) {

    auto creator = project->owner();
    auto tasks = project->tasks();

    mstch::array arr;

    tasks->bypass([&arr] (Task& task) {

        auto executor = task.user();

        arr.push_back(
                mstch::map{{"task", mstch::map{
                        {"title", std::string(task.title())},
                        {"description", std::string(task.description())},
                        {"name", std::string(executor->name())},
                        {"surname", std::string(executor->surname())},
                        {"deadline", std::string(task.deadline())}
                }}}
        );
    });

    mstch::map context{
            {"title", std::string(project->title())},
            {"description", std::string(project->description())},
            {"name", std::string(creator->name())},
            {"surname", std::string(creator->surname())},
            {"creation_date", std::string(project->creation_date())},
            {"tasks", arr}
    };

    return mstch::render(path("project.html"), context);
}

std::string Renderer::renderTask(std::shared_ptr<Task> task) {

    auto user = task->user();
    auto project = task->project();

    mstch::map context{
            {"title", std::string(task->title())},
            {"project", std::string(project->title())},
            {"description", std::string(task->description())},
            {"name", std::string(user->name())},
            {"surname", std::string(user->surname())},
            {"creation_date", std::string(task->creation_date())},
            {"deadline", std::string(task->deadline())}
    };

    return mstch::render(path("task.html"), context);
}

std::string Renderer::renderAddTask(std::shared_ptr<User> users) {
    mstch::array arr;

    users->bypass([&arr] (User& user) {

        arr.push_back(
                mstch::map{{"user", mstch::map{
                        {"name", std::string(user.name())},
                        {"surname", std::string(user.surname())},
                }}}
        );
    });

    mstch::map context{
            {"users", arr}
    };

    return mstch::render(path("addTask.html"), context);
}