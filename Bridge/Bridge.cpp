// 브릿지 패턴은 구현부와 추상부를 분리하여 독립적으로 변형할 수 있도록 하는 패턴이다.
#include <iostream>
using namespace std;

class Hunting_Handler {
  public:
    virtual void attack() = 0; // 메서드의 인터페이스를 정의합니다.
};

class Hunting_Method1 : public Hunting_Handler {
  public:
    void attack() override { std::cout << "할퀴기!" << std::endl; }
};

class Hunting_Method2 : public Hunting_Handler {
  public:
    void attack() override { std::cout << "물어뜯기!" << std::endl; }
};

class Animal {
  protected:
    Hunting_Handler* hunting_method;
  public:
    Animal(Hunting_Handler* method) : hunting_method(method) {}
};

class Cat : public Animal {
  public:
    Cat(Hunting_Handler* method) : Animal(method) {}

    void attack() {
        hunting_method->attack(); // 공격 메서드를 호출합니다.
    }
};

class Dog : public Animal {
  public:
    Dog(Hunting_Handler *method) : Animal(method) {}

    void attack() {
        hunting_method->attack(); // 공격 메서드를 호출합니다.
    }
};