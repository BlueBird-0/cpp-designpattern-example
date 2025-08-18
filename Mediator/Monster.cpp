#include "Monster.h"
#include "Mediator.h"

Monster::Monster() : m_hp(20), m_score(10), m_mediator(nullptr) {}

void Monster::attack() {
    if (m_hp <= 0) {
        std::cout << "Monster is dead." << std::endl;
    } else if (m_mediator != nullptr) {
        m_mediator->attackChar(5);
    }
}

void Monster::takeDamage(int damage) {
    m_hp -= damage;
    std::cout << "monster take damage: " << damage << std::endl;
    if (m_hp <= 0) {
        std::cout << "Monster is dead." << std::endl;
        dropScore();
    }
}

void Monster::dropScore() {
    if (m_mediator != nullptr) {
        m_mediator->addScore(m_score);
        std::cout << "Monster dropped score: " << m_score << std::endl;
    }
}

void Monster::setMediator(Mediator* m) { m_mediator = m; }
