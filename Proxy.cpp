// Proxy 패턴은 객체에 접근할 때 대리 객체를 사용해 접근을 제어하거나 기능을 추가하는 디자인 패턴입니다.
#include <iostream>
using namespace std;

struct MResultMatter {
    string name;
    int weight;
};

class Factory {
  public:
    virtual string process(string initialMatter, MResultMatter& resultMatter) = 0;
};

class FirstFactory : public Factory {
  public:
    string process(string initialMatter, MResultMatter& resultMatter) override {
        if(initialMatter != "A") {
            return initialMatter;
        }
        resultMatter.name = "gasoline";
        resultMatter.weight = 30;
        return "B";
    }
};

class NewFactory : public Factory { 
  public:
    string process(string initialMatter, MResultMatter& resultMatter) override {
        // NewFactory는 FirstFactory를 사용하여 초기 물질을 처리합니다.
        if(initialMatter == "A") {
            FirstFactory firstFactory;
            initialMatter = firstFactory.process(initialMatter, resultMatter);
        }

        if(initialMatter == "B") {
            if(resultMatter.name == "gasoline") {
                resultMatter.name = "gasoline + diesel";
                resultMatter.weight = 50;
                return "C";
            }else {
                resultMatter.name = "gasoline";
                resultMatter.weight = 30;
                return "C";
            }
        }
    }
};

// 여기서 Proxy는 NewFactory를 사용하여 FirstFactory를 사용하고 있습니다.
int main(int argc, char* argv[]) {
    MResultMatter resultMatter;
    NewFactory newFactory;
    string finalMatter = newFactory.process("A", resultMatter);
    cout << "이름: " << resultMatter.name << endl;
    cout << "무게: " << resultMatter.weight << endl;
    cout << "최종 물질: " << finalMatter << endl;

    return 0;
}