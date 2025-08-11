// Adapter Pattern은 기존의 인터페이스를 변경하지 않고도 새로운 인터페이스를 제공하는 패턴입니다. (콘센트에 어댑터를 연결하는 것과 비슷)
#include <iostream>
using namespace std;

// Target interface: 클라이언트가 기대하는 인터페이스
class Socket {
  public:
    virtual void connect() = 0;
};

// Adaptee: 기존 클래스 (인터페이스가 다름)
// KoreanPlug는 이미 만들어져 수정할 수 없다고 가정.
class KoreanPlug {
  public:
    void insertIntoKoreanSocket() {
        cout << "🔌 한국형 플러그가 한국 콘센트에 연결되었습니다.\n";
    }
};

// Adapter: 외국형 콘센트(=Socket)에 한국형 플러그를 꽂을 수 있게 해주는 어댑터
class PlugAdapter : public Socket {
  public:
    PlugAdapter(KoreanPlug* plug) : koreanPlug(plug) {}

    void connect() override {
        cout << "🧩 어댑터가 작동합니다!\n";
        koreanPlug->insertIntoKoreanSocket();  // 한국 플러그 인터페이스 호출
    }

  private:
    KoreanPlug* koreanPlug;
};

// Client 코드
void UseElectricDevice(Socket* socket) {
    cout << "⚡️ 전기 제품이 콘센트에 연결을 시도합니다...\n";
    socket->connect();
}
