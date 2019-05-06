//
// Created by Святослав Кряжев on 05.05.2019.
//

#ifndef MAIN_LOGIC_OBJECT_H
#define MAIN_LOGIC_OBJECT_H

#include <string>
#include <vector>

class Model {
public:
    const std::string& read(const std::string& key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw "No value associated with such key";
        }

        return it->second;
    }

    void write(const std::string& key, const std::string& value) {
        data.emplace(key, value);
    }

    unsigned long getFieldsCount() const {
        return data.size();
    }

protected:
    std::vector<std::string> data;

};

#endif //MAIN_LOGIC_OBJECT_H
