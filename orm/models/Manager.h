//
// Created by Святослав Кряжев on 24.04.2019.
//

#ifndef ORM_MANAGER_H
#define ORM_MANAGER_H

#include <unordered_map>
#include <string>
#include "Set.h"


using kwargs = std::unordered_map<std::string, std::string>;

template <typename Object>
class Meta;

template <typename Object>
class Manager {
public:
    Manager() = default;

    Object get(const kwargs& options) const {
        std::string prototype = "(";
        std::string values = "(";

        for (auto& optionIt : options) {
            auto metaIt = meta.fields.find(optionIt.first);
            if (metaIt == meta.fields.end()) {
                throw "Invalid option";
            }

            metaIt->second->check(optionIt.second);

            prototype += optionIt.first;
            prototype += ',';

            if (metaIt->second->needsScreening()) {
                values += "'" + optionIt.second + "'";
            } else {
                values += optionIt.second;
            }
            values += ',';
        }

        prototype.back() = ')';
        values.back() = ')';

        Object object;
        return object;
    }

    Set<Object> filter(const kwargs& options) const;

    void update(const kwargs& options) const;
    void remove(const kwargs& options) const;

    void save(Object& model) const;

    Meta<Object> meta;
private:

};


#endif //ORM_MANAGER_H
