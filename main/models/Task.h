//
// Created by Святослав Кряжев on 06.05.2019.
//

#ifndef MAIN_TASK_H
#define MAIN_TASK_H

#include <unordered_map>
#include "Model.h"
#include "CharField.h"
#include "TextField.h"
#include "IntegerField.h"
#include "DateTimeField.h"
#include "IntegerValidator.h"
#include "CharValidator.h"
#include "DateTimeValidator.h"


class Task;

template <>
struct Meta<Task> {
    Meta() {
        fields.emplace("id", new IntegerValidator);
        fields.emplace("title", new CharValidator);
        fields.emplace("description", new CharValidator);
        fields.emplace("user_id", new IntegerValidator);
        fields.emplace("project_id", new IntegerValidator);
        fields.emplace("creation_date", new DateTimeValidator);
        fields.emplace("deadline", new DateTimeValidator);
    }

    ~Meta() {
        for (auto& it : fields) {
            delete it.second;
        }
    }

    std::string tableName = "tasks";
    std::unordered_map<std::string, BaseValidator*> fields;
};

//-----------------------------------

struct Task : public Model<Task> {
    using Model::objects;

    Task() :
        id(objects.meta.fields.at("id")),
        title(objects.meta.fields.at("title")),
        description(objects.meta.fields.at("description")),
        user_id(objects.meta.fields.at("user_id")),
        project_id(objects.meta.fields.at("project_id")),
        creation_date(objects.meta.fields.at("creation_date")),
        deadline(objects.meta.fields.at("deadline")) {}

    IntegerField id;
    CharField title;
    TextField description;
    IntegerField user_id;
    IntegerField project_id;
    DateTimeField creation_date;
    DateTimeField deadline;
};

#endif //MAIN_TASK_H
