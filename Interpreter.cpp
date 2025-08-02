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

int main() {
    int pos = 0;
    string calStr = "1+2+3+4";
    int len = calStr.length();
    for(int i= pos + 1; i<len; i++) {
        if(calStr[i] == '+') {
            string leftStr = calStr.substr(pos, i - pos);
            string rightStr = calStr
            .substr(i + 1, len - i - 1);
            RegularExp* pLeftExp = new NumberExp(leftStr);
            RegularExp* pRightExp = new NumberExp(rightStr);
            RegularExp* pAddExp = new AddExp(pLeftExp, pRightExp);
            cout << "Result: " << pAddExp->cal() << endl;
            delete pLeftExp;
            delete pRightExp;
            delete pAddExp;
            break; // 단순화를 위해 첫 번째 '+'만 처리
        }
    }

    return 0;
}