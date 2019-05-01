//
// Created by Святослав Кряжев on 02.05.2019.
//

#include "Task.h"

Task::Task() :
        title(fields->find("title")->second),
        description(fields->find("description")->second),
        creation_date(fields->find("title")->second),
        deadline(fields->find("description")->second)
{

}