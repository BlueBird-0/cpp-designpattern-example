#include <gtest/gtest.h>
#include "FactoryMethod.cpp"

TEST(FactoryhMethod, TestMainFunction) {
    HwpApplication hwpApp;
    hwpApp.NewDocument("input.hwp");

    AnotherApplication anotherApp;
    anotherApp.NewDocument("input.doc");

    ConcreteApplication<MsWordDocument> app;
    app.NewDocument("input.doc");

    cout << "Hello Factory Method Pattern" << endl;
}