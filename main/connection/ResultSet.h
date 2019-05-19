//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef PSQL_CURSOR_H
#define PSQL_CURSOR_H

#include <libpq-fe.h>
#include <iostream>
//#include "exceptions/CursorIndexExceedsException.h"


class ResultSet {
public:
    explicit ResultSet(PGresult* _result) :
    	result(_result),
        objectsCount(PQntuples(_result)),
        fieldsCount(PQnfields(_result))
    {
    }

    ~ResultSet() { PQclear(result); }

    const char* get(int objectIndex, int fieldIndex) const {
//    	if (fieldIndex < 0 || fieldIndex >= fieldsCount) {
//    		throw CursorIndexExceedsException(fieldIndex, fieldsCount);
//    	}

    	return PQgetvalue(result, objectIndex, fieldIndex);
    }

    int getObjectsCount() const {
        return objectsCount;
    }

    int getFieldsCount() const {
        return fieldsCount;
    }

private:
    PGresult* result;

    const int objectsCount;
    const int fieldsCount;
};


#endif //PSQL_CURSOR_H

