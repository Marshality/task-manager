//
// Created by Юлия Плаксина on 2019-05-18.
//

#ifndef MY_PROJECT_FILETOSTRINGCONVERTER_H
#define MY_PROJECT_FILETOSTRINGCONVERTER_H

#include <fstream>
#include "exceptions/FileNotOpenException.h"


class FileToStringConverter {
public:
    explicit FileToStringConverter(const char* _templatesPath) : templatesPath(_templatesPath) {}

    std::string operator() (const std::string& filepath) {
        std::ifstream fstream;
        fstream.open(templatesPath + filepath, std::fstream::out);

        if (!fstream.is_open()) {
            throw FileNotOpenException();
        }

        std::string string;
        std::getline(fstream, string, '\0');

        fstream.close();

        return string;
    }

private:
    const std::string templatesPath;
};


#endif //MY_PROJECT_FILETOSTRINGCONVERTER_H
