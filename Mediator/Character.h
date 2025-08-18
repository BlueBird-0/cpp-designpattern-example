#pragma once
#include <iostream>
#include "Item.h"

class Mediator;

class Character {
public:
    Character();
    void attack();
    void takeDamage(int damage);
    void getMoney();
    void getItem();
    void setMediator(Mediator* m);

private:
    int m_hp;
    int m_score;
    Item* m_item;
    Mediator* m_mediator;
};