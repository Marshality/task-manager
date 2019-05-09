//
// Created by Святослав Кряжев on 22.04.2019.
//

#ifndef CONNECTION_INDEXEXCEEDSEXCEPTION_H
#define CONNECTION_INDEXEXCEEDSEXCEPTION_H

#include <exception>
#include <string>

class CursorIndexExceedsException : public std::exception {
public:
    explicit CursorIndexExceedsException(int _index, int _columnCount);

    const char* what() const noexcept override;

private:
    int index;
    int columnCount;

    std::string request;
};

CursorIndexExceedsException::CursorIndexExceedsException(int _index, int _columnCount) :
        index(_index),
        columnCount(_columnCount)
{
    request += std::string("CURSOR ERROR: index exceeds column count\n")
            + "Allowed index interval: (0, " + std::to_string(columnCount - 1) + ")\n"
            + "Requested index: " + std::to_string(index);
}

const char* CursorIndexExceedsException::what() const noexcept {
    return request.c_str();
}

#endif //CONNECTION_INDEXEXCEEDSEXCEPTION_H
