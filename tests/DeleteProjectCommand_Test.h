#ifndef TESTS_DELETEPROJECTCOMMAND_TEST_H
#define TESTS_DELETEPROJECTCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/DeleteProjectCommand.h"
#include "../Project/Receiver.h"

class DeleteProjectCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new DeleteProjectCommand(data1);

        DataPackage data2; // ID is missed
        cmd2 = new DeleteProjectCommand(data2);
    }

    DeleteProjectCommand* cmd1 = nullptr;
    DeleteProjectCommand* cmd2 = nullptr;
};

#endif //TESTS_DELETEPROJECTCOMMAND_TEST_H
