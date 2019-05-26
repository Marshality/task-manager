//
// Created by Marseille Gulaya on 2019-05-26.
//

#ifndef MAIN_URLPARSER_H
#define MAIN_URLPARSER_H

#include <vector>
#include <string>
#include "Types.h"

struct parsers {
    std::vector<std::string> parse(const std::string& urlString) {
        auto it = urlString.begin();
        auto endIt = urlString.end();
        if (urlString.back() == '/') {
            --endIt;
        }

        std::vector<std::string> urlParams;

        while (it != endIt) {
            if (*it == '/') {
                ++it;
            }

            auto findIt = std::find(it, endIt, '/');
            urlParams.emplace_back(it, findIt);
            it = findIt;
        }

        return urlParams;
    }
};

struct PostParser {
    string_map parse(const std::string& postString) {
        auto it = postString.begin();
        auto endIt = postString.end();

        string_map postParams;

        while (it != endIt) {
            auto findEqIt = std::find(it, endIt, '=');
            auto findSepIt = std::find(findEqIt, endIt, '&');

            auto key = std::string(it, findEqIt);
            auto value = std::string(++findEqIt, findSepIt);

            postParams.emplace(key, value);

            it = findSepIt;
            if (it != endIt) {
                ++it;
            }
        }

        return postParams;
    }
};

//
//     urlpatterns{
//            boost::regex(""),
//            boost::regex("signin/"),
//            boost::regex("signup/"),
//            boost::regex("success/?"),
//            boost::regex("[A-Za-z0-9_]{1, 64}/?"),
//            boost::regex("[A-Za-z0-9_]{1, 64}/new/?"),
//            boost::regex("[A-Za-z0-9_]{1, 64}/[1-9][0-9]{0, 10}/?"),
//            boost::regex("[A-Za-z0-9_]{1, 64}/[1-9][0-9]{0, 10}/new/?"),
//            boost::regex("[A-Za-z0-9_]{1, 64}/[1-9][0-9]{0, 10}/[1-9][0-9]{0, 10}/?")
//    };




#endif //MAIN_URLPARSER_H
