#include "gtest/gtest.h"
#include "CreateProjectCommand_Test.h"
#include "CreateTaskCommand_Test.h"
#include "DeleteProjectCommand_Test.h"
#include "DeleteTaskCommand_Test.h"
#include "EditProjectCommand_Test.h"
#include "EditTaskCommand_Test.h"

// CreateProjectCommand

TEST_F(CreateProjectCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(CreateProjectCommand_Test, NecessaryFieldsAreMissed) {
    EXPECT_THROW(cmd2->execute(), FieldIsMissedException);
    EXPECT_THROW(cmd3->execute(), FieldIsMissedException);
    EXPECT_THROW(cmd4->execute(), FieldIsMissedException);
}

// CreateProjectCommand


// CreateTaskCommand

TEST_F(CreateTaskCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(CreateTaskCommand_Test, NecessaryFieldsAreMissed) {
    EXPECT_THROW(cmd2->execute(), FieldIsMissedException);
}

// CreateTaskCommand


// DeleteProjectCommand

TEST_F(DeleteProjectCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(DeleteProjectCommand_Test, IdIsNotFound) {
    EXPECT_THROW(cmd2->execute(), IdIsNotFoundException);
}

// DeleteProjectCommand


// DeleteTaskCommand

TEST_F(DeleteTaskCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(DeleteTaskCommand_Test, IdIsNotFound) {
    EXPECT_THROW(cmd2->execute(), IdIsNotFoundException);
}

// DeleteTaskCommand


// EditProjectCommand

TEST_F(EditProjectCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(EditProjectCommand_Test, IdIsNotFound) {
    EXPECT_THROW(cmd2->execute(), IdIsNotFoundException);
}

// EditProjectCommand


// EditTaskCommand

TEST_F(EditTaskCommand_Test, EverythingIsFine) {
    ASSERT_NO_THROW(cmd1->execute());
}

TEST_F(EditTaskCommand_Test, IdIsNotFound) {
    EXPECT_THROW(cmd2->execute(), IdIsNotFoundException);
}

// EditTaskCommand

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}