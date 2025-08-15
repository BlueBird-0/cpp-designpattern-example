#include <gtest/gtest.h>
#include "Composite.cpp"

TEST(CompositeTest, PriceCalculation) {
    Ten ten;
    Hundred hundred;
    Thousand thousand;

    CompositeMoney compositeMoney;
    compositeMoney.Add(&ten); // Ten 객체를 추가합니다.
    compositeMoney.Add(&hundred); // Hundred 객체를 추가합니다.
    compositeMoney.Add(&thousand); // Thousand 객체를 추가합니다.

    cout << "Total price: " << compositeMoney.price() << endl; // 총 가격을 출력합니다.
    cout << "Child price: " << compositeMoney.GetChild(0)->price() << endl; // 첫 번째 자식 객체의 가격을 출력합니다.
    cout << "Child price: " << compositeMoney.GetChild(1)->price() << endl; // 두 번째 자식 객체의 가격을 출력합니다.
    cout << "Child price: " << compositeMoney.GetChild(2)->price() << endl; // 세 번째 자식 객체의 가격을 출력합니다.

}