#include "templater/render.h"
#include <iostream>

int main() {

    std::fstream mainFile;
    mainFile.open("../rendered/mainOut.html", std::fstream::out);
    if (mainFile.is_open()) {
        mainFile << base(mainPage(), "Главная");
        mainFile.close();
    }
    else {
        std::cout << "Файл не был открыт";
    }

    std::fstream projectListFile;
    projectListFile.open("../rendered/projectListOut.html", std::fstream::out);
    if (projectListFile.is_open()) {
        projectListFile << base(projectList(), "Список проектов");
        projectListFile.close();
    }
    else {
        std::cout << "Файл не был открыт";
    }

    std::fstream projectFile;
    projectFile.open("../rendered/projectOut.html", std::fstream::out);
    if (projectFile.is_open()) {
        projectFile << base(project(), "Проект");
        projectFile.close();
    }
    else {
        std::cout << "Файл не был открыт";
    }

    std::fstream taskFile;
    taskFile.open("../rendered/taskOut.html", std::fstream::out);
    if (taskFile.is_open()) {
        taskFile << base(task(), "Задача");
        taskFile.close();
    }
    else {
        std::cout << "Файл не был открыт";
    }

    return 0;
}