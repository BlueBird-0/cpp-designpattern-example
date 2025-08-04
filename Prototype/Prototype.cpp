// 프로토타입은 코드를 그들의 클래스들에 의존시키지 않고 기존 객체들을 복사할 수 있도록 하는 생성 디자인 패턴입니다. 프로토타입 디자인 패턴
#include <iostream>
#include <list>
using namespace std;

class Position {
  public:
    Position() {}
    Position(int x, int y) : x_(x), y_(y) {}
    int x_, y_;
};

class Graphic {
  public:
    virtual void Draw(Position& pos) = 0;
    virtual Graphic* Clone() = 0;
};

class Triangle : public Graphic {
  public:
    void Draw(Position& pos) {}
    Graphic *Clone() override { return new Triangle(*this); }
};

class Rectangle : public Graphic {
  public:
    void Draw(Position& pos) {}
    Graphic *Clone() override { return new Rectangle(*this); }
};

class GraphicComposite : public Graphic {
  public:
    void Draw(Position& pos) {
        cout << "Drawing GraphicComposite at (" << pos.x_ << ", " << pos.y_ << ")\n";
        for (auto graphic : graphics_) {
            graphic->Draw(pos); // 내부 구성 요소도 같이 그림
        }
    }
    Graphic *Clone() override {
        GraphicComposite *pGraphicComposite = new GraphicComposite(*this);
        list<Graphic *>::iterator iter1;
        list<Graphic *>::iterator iter2;
        iter2 = pGraphicComposite->graphics_.begin();
        for (iter1 = graphics_.begin(); iter1 != graphics_.end(); ++iter1) {
            Graphic *pNewGraphic = (*iter1)->Clone();
            *iter2 = pNewGraphic;
            iter2++;
        }
        return pGraphicComposite;
    }
    void Add(Graphic *graphic) { graphics_.push_back(graphic); }

  private:
    list<Graphic *> graphics_;
};