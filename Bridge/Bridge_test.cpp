#include <gtest/gtest.h>
#include "Bridge.cpp"

TEST(BridgePatternTest, CatAttackWithMethod1) {
    Cat cat(new Hunting_Method1());
    cat.attack(); // 할퀴기!
    Dog dog(new Hunting_Method2()); 
    dog.attack(); // 물어뜯기!
}