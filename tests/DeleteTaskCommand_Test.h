#ifndef TESTS_DELETETASKCOMMAND_TEST_H
#define TESTS_DELETETASKCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/DeleteProjectCommand.h"
#include "../Project/Receiver.h"

class DeleteTaskCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new DeleteTaskCommand(data1);

        DataPackage data2; // ID is missed
        cmd2 = new DeleteTaskCommand(data2);
    }

    DeleteTaskCommand* cmd1 = nullptr;
    DeleteTaskCommand* cmd2 = nullptr;
};

#endif //TESTS_DELETETASKCOMMAND_TEST_H
