#include <gtest/gtest.h>
#include "Command.cpp"

TEST(CommandTest, Execute) {
    registerCommand();
    
    string input;
    cin >> input;

    Command* command = commandMap[input];// 명령어를 찾습니다.
    command->execute();
}