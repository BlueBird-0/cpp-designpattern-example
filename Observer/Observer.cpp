// Observer패턴은 객체 간의 일대다 의존성을 정의하여, 한 객체의 상태 변화가 의존하는 모든 객체에 자동으로 통지되도록 하는 디자인 패턴입니다.
// 이 패턴은 주로 이벤트 기반 시스템에서 사용되며, 객체 간의 느슨한 결합을 유지하는 데 유용합니다.
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Observer {
  public:
    virtual ~Observer() = default; // 가상 소멸자는 다형적 소멸을 위해 필수입니다.
    virtual void update(const string &news, const string &title) = 0;
};

class Publisher {
  public:
    virtual ~Publisher() = default; // 가상 소멸자
    virtual void addObserver(Observer& observer) = 0;
    virtual void removeObserver(Observer& observer) = 0;
    virtual void notifyObservers() = 0;
};

class NewsPublisher : public Publisher {
  public:
    void addObserver(Observer& observer) override {
        observers.push_back(&observer);
    }

    void removeObserver(Observer& observer) override {
        observers.remove(&observer);
    }

    void notifyObservers() override {
        for (auto* observer : observers) {
            observer->update(m_news, m_title);
        }
    }

    void setNewsInfo(const string &news, const string &title) {
        m_news = news;
        m_title = title;
        notifyObservers();
    }

  private:
    list<Observer*> observers; // Observer 객체에 대한 포인터 리스트
    string m_news;
    string m_title;
};

class AnnualSubscriber : public Observer {
  public:
    void update(const string &news, const string &title) override {
        cout << "AnnualSubscriber: New news available!" << endl;
        cout << "Title: " << title << endl;
        cout << "News: " << news << endl;
        cout << "AnnualSubscriber: Enjoy your annual subscription!" << endl << endl;
    }
};

class EventSubscriber : public Observer {
  public:
    void update(const string &news, const string &title) override {
        cout << "EventSubscriber: New event notification!" << endl;
        cout << "Title: " << title << endl;
        cout << "News: " << news << endl;
        cout << "EventSubscriber: Enjoy your event subscription!" << endl << endl;
    }
};