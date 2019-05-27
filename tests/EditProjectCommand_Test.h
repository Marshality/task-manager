#ifndef TESTS_EDITPROJECTCOMMAND_TEST_H
#define TESTS_EDITPROJECTCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/EditProjectCommand.h"
#include "../Project/Receiver.h"

class EditProjectCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new EditProjectCommand(data1);

        DataPackage data2; // ID is missed
        cmd2 = new EditProjectCommand(data2);
    }

    EditProjectCommand* cmd1 = nullptr;
    EditProjectCommand* cmd2 = nullptr;
};

#endif //TESTS_EDITPROJECTCOMMAND_TEST_H
