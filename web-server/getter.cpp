//
// Created by Marseille Gulaya on 2019-05-20.
//

#include "getter.h"

std::map<std::string, std::string> getParams(std::string& request) {
    std::istringstream iss(request);

    std::string method;
    std::string query;
    std::string protocol;

    // reset the std::istringstream with the query string

    iss.clear();
    iss.str(query);

    std::string url;

    std::getline(iss, url, '?');

    // store query key/value pairs in a map
    std::map<std::string, std::string> params;

    std::string keyval, key, val;

    while (std::getline(iss, keyval, '&')) // split each term
    {
        std::istringstream iss(keyval);

        // split key/value pairs
        if (std::getline(std::getline(iss, key, '='), val))
        params[key] = val;
    }
//
//    std::cout << "protocol: " << protocol << '\n';
//    std::cout << "method  : " << method << '\n';
//    std::cout << "url     : " << url << '\n';
//
//    for (auto const& param: params)
//        std::cout << "param   : " << param.first << " = " << param.second << '\n';

    return params;
}