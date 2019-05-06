//
// Created by Святослав Кряжев on 05.05.2019.
//

#include "MainManager.h"

MainManager::MainManager() :
    connection("host=localhost port=2389 dbname=crab user=jason password=")
{
    set taskSet;
    taskSet.emplace_back("");
}