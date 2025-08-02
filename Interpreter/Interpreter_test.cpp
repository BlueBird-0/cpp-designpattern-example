#include <gtest/gtest.h>
#include "Interpreter.cpp"

TEST(InterpreterTest, TestMainFunction) {
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
}