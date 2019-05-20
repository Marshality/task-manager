//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_STORAGEQUICKACCESS_H
#define MAIN_STORAGEQUICKACCESS_H

#include "Storage.h"
#include "Types.h"

template <typename Object>
struct StorageAccess {
    static std::shared_ptr<Object> getOne(const string_map& kwargs) {
        return Storage::getInstance().getOne<Object>(kwargs);
    }

    static std::shared_ptr<Set<Object>> getMany(const string_map& kwargs) {
        return Storage::getInstance().getMany<Object>(kwargs);
    }
};

#endif //MAIN_STORAGEQUICKACCESS_H
