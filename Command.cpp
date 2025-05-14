// Command패턴은 객체의 요청을 캡슐화하여, 요청을 실행, 로그를 남기기, 취소, 큐에 넣기 등등 을 가능하게 해주는 행위(Behavioral) 패턴이다.
#include <iostream>
#include <map>
using namespace std;

#define EAT "eat"
#define TALK "talk"
#define KICK "kick"
#define WALK "walk"

class Mouse {
  public:
    void eat() { cout << "eat Function" << endl; }
    void talk() { cout << "talk Function" << endl; }
};

class Leg {
  public:
    void kick() { cout << "kick Function" << endl; }
    void walk() { cout << "walk Function" << endl; }
};

class Command {
  public:
    virtual void execute() = 0;
};

class EatCommand : public Command {
  public:
    EatCommand(Mouse* mouse) : mouse(mouse) {}
    void execute() override { mouse->eat(); }
  private:
    Mouse* mouse;
};

class TalkCommand : public Command {
  public:
    TalkCommand(Mouse* mouse) : mouse(mouse) {}
    void execute() override { mouse->talk(); }
  private:
    Mouse* mouse;
};

class KickCommand : public Command {
  public:
    KickCommand(Leg* leg) : leg(leg) {}
    void execute() override { leg->kick(); }
  private:
    Leg* leg;
};

class WalkCommand : public Command {
  public:
    WalkCommand(Leg* leg) : leg(leg) {}
    void execute() override { leg->walk(); }
  private:
    Leg* leg;
};

map<string, Command*> commandMap;
void registerCommand() {
    commandMap[EAT] = new EatCommand(new Mouse());
    commandMap[TALK] = new TalkCommand(new Mouse());
    commandMap[KICK] = new KickCommand(new Leg());
    commandMap[WALK] = new WalkCommand(new Leg());
}

int main(int argc, char *argv[]) {
    registerCommand();
    
    string input;
    cin >> input;

    Command* command = commandMap[input];// 명령어를 찾습니다.
    command->execute();
    return 0;
}