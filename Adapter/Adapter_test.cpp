#include <gtest/gtest.h>
#include "Adapter.cpp"

TEST(Facade, TestMainFunction) {
    KoreanPlug* myPlug = new KoreanPlug();
    Socket* adapter = new PlugAdapter(myPlug);  // 어댑터를 통해 외국 콘센트에 연결

    UseElectricDevice(adapter);

    delete myPlug;
    delete adapter;
}