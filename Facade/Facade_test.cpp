#include <gtest/gtest.h>
#include "Facade.cpp"

TEST(Facade, TestMainFunction) {
    Food* food = new Food("치킨");
    DigestHandler digestHandler(food);
    cout << digestHandler.digetsResult() << endl; // 복잡한 내부 내용을 숨김
}