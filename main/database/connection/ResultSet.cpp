//
// Created by Святослав Кряжев on 20.05.2019.
//

#include "ResultSet.h"

#include <libpq-fe.h>
#include "exceptions/CursorIndexExceedsException.h"


ResultSet::ResultSet(PGresult* _result) :
        result(_result),
        objectsCount(PQntuples(_result)),
        fieldsCount(PQnfields(_result)) {}

ResultSet::~ResultSet() {
    PQclear(result);
}

const char* ResultSet::get(int objectIndex, int fieldIndex) const {
    if (fieldIndex < 0 || fieldIndex >= fieldsCount) {
        throw CursorIndexExceedsException(fieldIndex, fieldsCount);
    }

    return PQgetvalue(result, objectIndex, fieldIndex);
}

int ResultSet::getObjectsCount() const {
    return objectsCount;
}

int ResultSet::getFieldsCount() const {
    return fieldsCount;
}

bool ResultSet::isOk() const {
    return PQresultStatus(result) == PGRES_COMMAND_OK || PQresultStatus(result) == PGRES_TUPLES_OK;
}

bool ResultSet::isEmpty() const {
    return objectsCount == 0;
}
