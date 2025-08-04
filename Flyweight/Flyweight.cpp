// Flyweight(경량)패턴은 공유 가능한 객체(내부상태)를 재사용해 메모리 사용을 줄이고 성능을 향상시키는 패턴입니다.
#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

// 공유 객체 (내부 상태: color만 가지고 있음)
class Tree {
public:
    Tree(const string& color) : color(color) {}
    void install(int x, int y) {
        cout << "x:" << x << " y:" << y << " 위치에 " << color << "색 나무를 설치했습니다!" << endl;
    }
private:
    string color;
};

// TreeFactory: 같은 색 나무는 재사용함
class TreeFactory {
public:
    static shared_ptr<Tree> getTree(const string& color) {
        if (trees.find(color) == trees.end()) { // 색이 없으면 인스턴스를 새로 생성
            trees[color] = make_shared<Tree>(color);
            cout << "새 객체 생성" << endl;
        }
        return trees[color];
    }
private:
    static unordered_map<string, shared_ptr<Tree>> trees;
};

unordered_map<string, shared_ptr<Tree>> TreeFactory::trees;1