#include <gtest/gtest.h>
#include "Prototype.cpp"

TEST(PrototypeTest, TestMainFunction) {
    Position pos(10, 20);

    // 기본 도형들
    Triangle* t1 = new Triangle();
    Rectangle* r1 = new Rectangle();

    // 복합 도형 생성
    GraphicComposite* group1 = new GraphicComposite();
    group1->Add(t1); 
    group1->Add(r1);

    // 복합 도형 복제 (Prototype)
    Graphic* group2 = group1->Clone();

    // 각각의 도형 그리기
    cout << "Original group:\n";
    group1->Draw(pos);

    cout << "Cloned group:\n";
    group2->Draw(pos);

    // 메모리 정리 (간단히 처리)
    delete group1;
    delete group2;
}