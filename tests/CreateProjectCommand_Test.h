#ifndef TESTS_CREATEPROJECTCOMMAND_TEST_H
#define TESTS_CREATEPROJECTCOMMAND_TEST_H

#include "gtest/gtest.h"
#include "../Project/commands/CreateProjectCommand.h"
#include "../Project/Receiver.h"

class CreateProjectCommand_Test : public ::testing::Test {
protected:
    void SetUp() override {
        DataPackage data1; // Success
        cmd1 = new CreateProjectCommand(data1);

        DataPackage data2; // Title is missed
        cmd2 = new CreateProjectCommand(data2);

        DataPackage data3; // Description is missed
        cmd3 = new CreateProjectCommand(data3);

        DataPackage data4; // Both fields are missed
        cmd4 = new CreateProjectCommand(data4);
    }

    CreateProjectCommand* cmd1 = nullptr;
    CreateProjectCommand* cmd2 = nullptr;
    CreateProjectCommand* cmd3 = nullptr;
    CreateProjectCommand* cmd4 = nullptr;
};

#endif //TESTS_CREATEPROJECTCOMMAND_TEST_H
