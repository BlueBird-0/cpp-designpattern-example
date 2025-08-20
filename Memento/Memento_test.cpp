#include <gtest/gtest.h>
#include <iostream>
#include "Memento.cpp"

TEST(Memento, Main) {
    GoHistory history;

    history.clickNewPage("a");
    history.clickNewPage("b");
    history.clickNewPage("c");
    history.printHistory();
    std::cout<< "-----history-----" << std::endl;

    history.goBack(2);
    history.printHistory();
}