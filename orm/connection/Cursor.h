//
// Created by Святослав Кряжев on 19.04.2019.
//

#ifndef ORM_CURSOR_H
#define ORM_CURSOR_H

#include <libpq-fe.h>

namespace wrapper {

    class Cursor {
    public:
        explicit Cursor(PGresult* _result);
        ~Cursor() { PQclear(result); }

        bool next() const;
        void reset() const { position = -1; }

        const char* get(int field) const;



    private:
        PGresult* result;

        mutable int position = -1;
        const int objectsCount;
        const int fieldsCount;

    };

}

#endif //ORM_CURSOR_H
