//
// Created by Святослав Кряжев on 19.04.2019.
//

#include "Cursor.h"

Cursor::Cursor(PGresult* _res) :
    res(_res),
    objectsCount(PQntuples(res)),
    fieldsCount(PQnfields(res))
{

}

bool Cursor::next() const
{
    auto inc = (position + 1 < objectsCount);
    position += inc;

    return inc;
}

const char* Cursor::get(int field) const
{
    if (field < 0 || field >= fieldsCount) {
        throw "Exceeds";
    }

    return PQgetvalue(res, position, field);
}