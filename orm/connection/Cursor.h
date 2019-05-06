//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef ORM_CURSOR_H
#define ORM_CURSOR_H

#include <libpq-fe.h>
#include "CursorIndexExceedsException.h"


class Cursor {
public:
    explicit Cursor(PGresult* _result) :
    	result(_result),
        objectsCount(PQntuples(_result)),
        fieldsCount(PQnfields(_result)) {}

    ~Cursor() { PQclear(result); }

    bool next() const {
    	// Increment will have 0 value, if cursor at the end of result set
    	auto increment = (position + 1 < objectsCount);
    	position += increment;

    	return increment;
    }

    void reset() const { position = -1; }


    const char* get(int fieldIndex) const {
    	if (fieldIndex < 0 || fieldIndex >= fieldsCount) {
    		throw CursorIndexExceedsException(fieldIndex, fieldsCount);
    	}

    	return PQgetvalue(result, position, fieldIndex);
    }

private:
    PGresult* result;

    mutable int position = -1;
    const int objectsCount;
    const int fieldsCount;
};


#endif //ORM_CURSOR_H
