//
// Created by Святослав Кряжев on 20.05.2019.
//

#ifndef MAIN_STORAGEQUICKACCESS_H
#define MAIN_STORAGEQUICKACCESS_H

#include "Storage.h"

template <typename Object>
struct StorageQuickAccess {
    static std::shared_ptr<Object> getOne() {
        return Storage::getInstance().getOne<Object>("");
    }

    static std::shared_ptr<Set<Object>> getMany() {
        return Storage::getInstance().getMany<Object>("");
    }
};

#endif //MAIN_STORAGEQUICKACCESS_H
