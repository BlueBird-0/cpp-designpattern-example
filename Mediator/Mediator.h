#pragma once
#include "Item.h"

class Character;
class Monster;
class Contributor;

class Mediator {
public:
    Mediator(Character* ch, Monster* m, Contributor* ct);

    void attackChar(int power);
    void attackMonster(int power);
    void addScore(int score);
    int takeScore();
    Item* getItem(int score);

private:
    int m_score{};
    Character* m_character;
    Monster* m_monster;
    Contributor* m_contributor;
};
