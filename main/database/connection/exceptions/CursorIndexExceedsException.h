//
// Created by Святослав Кряжев on 22.04.2019.
//

#ifndef CONNECTION_INDEXEXCEEDSEXCEPTION_H
#define CONNECTION_INDEXEXCEEDSEXCEPTION_H

#include <string>
#include <exception>

class CursorIndexExceedsException : public std::exception {
public:
    explicit CursorIndexExceedsException(int _index, int _fieldsCount) noexcept;

    const char* what() const noexcept override;

private:
    int index;
    int fieldsCount;
};

CursorIndexExceedsException::CursorIndexExceedsException(int _index, int _fieldsCount) noexcept :
        index(_index),
        fieldsCount(_fieldsCount)
{
}

const char* CursorIndexExceedsException::what() const noexcept {
    auto errorMessage = std::string("CURSOR ERROR: index exceeds fields count\n")
                    + "Allowed index interval: (0, " + std::to_string(fieldsCount - 1) + ")\n"
                    + "Requested index: " + std::to_string(index);

    return errorMessage.c_str();
}

#endif //CONNECTION_INDEXEXCEEDSEXCEPTION_H
