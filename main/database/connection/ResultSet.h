//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef PSQL_CURSOR_H
#define PSQL_CURSOR_H


struct pg_result;

class ResultSet {
public:
    explicit ResultSet(pg_result* _result);
    ~ResultSet();

    const char* get(int objectIndex, int fieldIndex) const;

    int getObjectsCount() const;
    int getFieldsCount() const;

    bool isOk() const;
    bool isEmpty() const;

private:
    pg_result* result;

    const int objectsCount;
    const int fieldsCount;
};


#endif //PSQL_CURSOR_H

