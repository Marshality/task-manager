//
// Created by Святослав Кряжев on 19.04.2019.
//

#include <CursorIndexExceedsException.h>

#include "Cursor.h"

Cursor::Cursor(PGresult* _result) :
        result(_result),
        objectsCount(PQntuples(_result)),
        fieldsCount(PQnfields(_result))
{

}

bool Cursor::next() const {
    // Increment will have 0 value, if cursor at the end of result set
    auto increment = (position + 1 < objectsCount);
    position += increment;

    return increment;
}

const char* Cursor::get(int fieldIndex) const {
    if (fieldIndex < 0 || fieldIndex >= fieldsCount) {
        throw CursorIndexExceedsException(fieldIndex, fieldsCount);
    }

    return PQgetvalue(result, position, fieldIndex);
}