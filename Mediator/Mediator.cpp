#include "Mediator.h"
#include "Character.h"
#include "Monster.h"
#include "Contributor.h"

Mediator::Mediator(Character* ch, Monster* m, Contributor* ct)
    : m_character(ch), m_monster(m), m_contributor(ct), m_score(0) {}

void Mediator::attackChar(int power) { m_character->takeDamage(power); }
void Mediator::attackMonster(int power) { m_monster->takeDamage(power); }
void Mediator::addScore(int score) { m_score += score; }

int Mediator::takeScore() {
    int result = m_score;
    m_score = 0;
    return result;
}

Item* Mediator::getItem(int score) { return m_contributor->giveItem(score); }
