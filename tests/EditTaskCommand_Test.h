#ifndef TESTS_EDITTASKCOMMAND_TEST_H
#define TESTS_EDITTASKCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/EditProjectCommand.h"
#include "../Project/Receiver.h"

class EditTaskCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new EditTaskCommand(data1);

        DataPackage data2; // ID is missed
        cmd2 = new EditTaskCommand(data2);
    }

    EditTaskCommand* cmd1 = nullptr;
    EditTaskCommand* cmd2 = nullptr;
};

#endif //TESTS_EDITTASKCOMMAND_TEST_H
