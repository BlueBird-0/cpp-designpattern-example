// ChainOfResponsibility 패턴은 여러 객체가 연결된 사슬형태로 구성되어, 각 차례대로 책임을 가지는 디자인 패턴이다.
#include <iostream>
using namespace std;

class Answer {
  public:
    Answer(Answer *pObj = nullptr, string answerMsg = "")
        : pSuccessor(pObj), answerMsg(answerMsg) {}
    virtual void setAnswer(Answer *pObj, string answerMsg) {
        pSuccessor = pObj;    // 다음 객체를 설정합니다.
        answerMsg = answerMsg; // 메시지를 설정합니다.
    }
    virtual bool hasAnswer() { return !answerMsg.empty(); }
    virtual void handleAsk() { if(pSuccessor) pSuccessor->handleAsk(); }
    virtual void showAnswer() { cout << answerMsg << endl; }

  protected:
    string answerMsg;
  private:
    Answer* pSuccessor; // 다음 객체를 가리키는 포인터입니다.
};

class SpecificDepartmentAnswer : public Answer {
  public:
    SpecificDepartmentAnswer(string answerMsg = "") : Answer(nullptr, answerMsg) {}
    virtual void handleAsk() override {
        if( hasAnswer() ) {
            showAnswer();
        }else {
            Answer::handleAsk();
        }
    }
    virtual void showAnswer() override {
        cout << answerMsg << endl;
    }
};

class InternetAnswer : public Answer {
  public:
    InternetAnswer(Answer* pObj = nullptr, string answerMsg = "") : Answer(pObj, answerMsg) {}
    virtual void handleAsk() override {
        if( hasAnswer()) {
            showAnswer();
        }else {
            Answer::handleAsk();
        }
    }
    virtual void showAnswer() override {
        cout << answerMsg << endl;
    }
}; 