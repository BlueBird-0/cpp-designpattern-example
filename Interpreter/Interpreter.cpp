// Interpreter 패턴은 주어진 언어나 문법에 따라 표현식을 해석하고 처리하는 디자인 패턴입니다.
#include <iostream>
using namespace std;

class RegularExp {
public:
    virtual int cal() = 0;
};

class NumberExp : public RegularExp {
public:
    NumberExp(const char* pStr) : number(atoi(pStr)) {}
    NumberExp(const string str) : number(atoi(str.c_str())) {}

    int cal() override {
        return number;
    }
private:
    int number;
};

class AddExp : public RegularExp {
public:
    AddExp(RegularExp* pExp1, RegularExp* pExp2) : pExp1(pExp1), pExp2(pExp2) {}

    int cal() override {
        return pExp1->cal() + pExp2->cal();
    }

private:
    RegularExp* pExp1;
    RegularExp* pExp2;
};