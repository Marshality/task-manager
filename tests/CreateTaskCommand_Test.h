#ifndef TESTS_CREATETASKCOMMAND_TEST_H
#define TESTS_CREATETASKCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/CreateTaskCommand.h"
#include "../Project/Receiver.h"

class CreateTaskCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new CreateTaskCommand(data1);

        DataPackage data2; // Title is missed
        cmd2 = new CreateTaskCommand(data2);
    }

    CreateTaskCommand* cmd1 = nullptr;
    CreateTaskCommand* cmd2 = nullptr;
};

#endif //TESTS_CREATETASKCOMMAND_TEST_H
