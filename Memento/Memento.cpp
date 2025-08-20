// Memento 패턴이란 객체의 구현 세부사항을 공개하지 않고, 객체의 이전 상태를 저장/복원 할 수 있게 해주는 행동 디자인 패턴입니다.
#include <iostream>
#include <list>
using namespace std;

class GoMemento {
public:
    GoMemento() : address(""), content("") { };
    void getContent() { //주소에 따라  내용 얻어오기
        if(address == "a")
            content = "aaa";
        else if(address == "b")
            content = "bbb";
        else
            content = "---";
    }
    string address;
    string content;
};

class GoHistory {
public:
    GoHistory() {
        m_curHistory = new GoMemento();
    }
    void clickNewPage(const string& addr) {
        GoMemento* newHistory = new GoMemento();
        newHistory->address = addr;
        newHistory->getContent();
        m_historyList.push_front(newHistory);
        m_curHistory = newHistory;
    }

    void goBack(int cnt) {
        if(cnt <= 0) return;
        for(int i=0; i<cnt; i++) {
            GoMemento* tmpHistory = m_historyList.front();
            delete tmpHistory;
            m_historyList.pop_front();
        }
    }

    void printHistory() {
        for(auto e : m_historyList) {
            cout << e->address << " " << e->content << endl;
        }
    }
private:
    list<GoMemento*> m_historyList;
    GoMemento* m_curHistory;
};
