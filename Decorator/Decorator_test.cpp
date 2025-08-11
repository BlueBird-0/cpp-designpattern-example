#include <gtest/gtest.h>
#include "Decorator.cpp"

TEST(Facade, TestMainFunction) {
    EatingMouse* pSoupEatingMouse = new SoupEatingMouse(); // 기본 객체 생성
    EatingMouse* pMeatEatingMouse = new MeatEatingMouse(pSoupEatingMouse); // MeatEatingMouse로 장식
    EatingMouse* pVegetableEatingMouse = new VegetableEatingMouse(pMeatEatingMouse); // VegetableEatingMouse로 장식

    pMeatEatingMouse->eat();    // 기본기능인 "국물 먹기" 와 "고기 먹기"가 출력됩니다.
    
    //pVegetableEatingMouse->eat();
}