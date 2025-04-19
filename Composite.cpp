// Composite 패턴은 복합 객체를 구성하는 개별적인 객체들을 모두 동일한 방법으로 다룰 수 있게 하는 패턴
#include <iostream>
#include <list>
using namespace std;

class Money {
  public:
    virtual int price() = 0;
    virtual void Add(Money* obj){}
    virtual Money* GetChild(int index) { return nullptr; } // 자식 객체를 가져오는 메서드입니다.
};

class Ten : public Money {
    int price() override { return 10; }
};

class Hundred : public Money {
    int price() override { return 100; }
};

class Thousand : public Money {
    int price() override { return 1000; }
};

// Composite 클래스는 Maoney 객체를 포함할 수 있는 클래스입니다.
class CompositeMoney : public Money {
  public:
    int price() {
        list<Money*>::iterator iter1;
        int sum = 0;
        for (iter1 = components.begin(); iter1 != components.end(); iter1++) {
            sum += (*iter1)->price(); // 각 Money 객체의 가격을 더합니다.
        }
        return sum;
    }

    void Add(Money* obj) override {
        components.push_back(obj); // Money 객체를 리스트에 추가합니다.
    }

    Money* GetChild(int index) override {
        list<Money*>::iterator iter1 = components.begin();
        advance(iter1, index); // 리스트의 index 위치로 이동합니다.
        return *iter1; // 해당 위치의 Money 객체를 반환합니다.
    }

  private:
    list<Money*> components; // Money 객체를 포함하는 리스트입니다.
};

int main(int argc, char *argv[]) {
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

    return 0;
}