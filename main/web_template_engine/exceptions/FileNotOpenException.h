//
// Created by Юлия Плаксина on 2019-05-22.
//

#ifndef MAIN_FILENOTOPENEXCEPTION_H
#define MAIN_FILENOTOPENEXCEPTION_H

#include <exception>
#include <string>

class FileNotOpenException : public std::exception {
public:
    const char* what() const noexcept override { return "Файл с шаблоном html не был открыт!"; }
};

#endif //MAIN_FILENOTOPENEXCEPTION_H
