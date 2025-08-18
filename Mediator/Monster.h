#pragma once
#include <iostream>

class Mediator;

class Monster {
public:
    Monster();
    void attack();
    void takeDamage(int damage);
    void dropScore();
    void setMediator(Mediator* m);

private:
    int m_hp;
    int m_score;
    Mediator* m_mediator;
};
