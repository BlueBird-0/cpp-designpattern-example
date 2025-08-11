// Decorator패턴은 기본 객체에 추가적인 기능을 동적으로 추가할 수 있는 패턴입니다.
// 이 패턴은 객체의 구조를 변경하지 않고도 기능을 확장할 수 있게 해줍니다.
#include <iostream>

using namespace std;

class EatingMouse {
  public:
    virtual void eat() = 0; // 순수 가상 함수
};

class SoupEatingMouse : public EatingMouse {
  public:
    void eat() override {
        cout << "국물 먹기" << endl;
    }
};

class Decorator: public EatingMouse {
  public:
    Decorator(EatingMouse* mouse) : mouse(mouse) {} // 생성자에서 EatingMouse 객체를 초기화합니다.
    void eat() override {
        mouse->eat(); // 기본 객체의 eat() 메서드를 호출합니다.
    }
  private:
    EatingMouse* mouse; // 기본 객체를 가리키는 포인터입니다.
};

class MeatEatingMouse: public Decorator {
  public:
    MeatEatingMouse(EatingMouse* mouse) : Decorator(mouse) {} // 생성자에서 기본 객체를 초기화합니다.
    void eat() override {
        Decorator::eat(); // 기본 객체의 eat() 메서드를 호출합니다.
        cout << "고기 먹기" << endl; // 추가 기능을 구현합니다.
    }
};

class VegetableEatingMouse: public Decorator {
  public:
    VegetableEatingMouse(EatingMouse* mouse) : Decorator(mouse) {} // 생성자에서 기본 객체를 초기화합니다.
    void eat() override {
        Decorator::eat(); // 기본 객체의 eat() 메서드를 호출합니다.
        cout << "채소 먹기" << endl; // 추가 기능을 구현합니다.
    }
};