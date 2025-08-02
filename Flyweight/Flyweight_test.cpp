#include <gtest/gtest.h>
#include "Flyweight.cpp"

TEST(InterpreterTest, TestMainFunction) {
    for (int i = 0; i < 5; ++i) {
        string color;
        cout << "나무 색 입력: ";
        cin >> color;

        auto tree = TreeFactory::getTree(color);
        int x = rand() % 100;
        int y = rand() % 100;
        tree->install(x, y);
    }
}