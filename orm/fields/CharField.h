//
// Created by Святослав Кряжев on 21.04.2019.
//

#ifndef ORM_CHARFIELD_H
#define ORM_CHARFIELD_H

#include <string>

class CharField {
public:
    CharField& operator=(const std::string& _data);

private:
    std::string data;
};

#endif //ORM_CHARFIELD_H
