#include "Character.h"
#include "Mediator.h"

Character::Character() : m_hp(20), m_score(10), m_item(nullptr), m_mediator(nullptr) {}

void Character::attack() {
    if (m_mediator != nullptr) {
        m_mediator->attackMonster(10);
    }
}

void Character::takeDamage(int damage) {
    m_hp -= damage;
    std::cout << "character take damage: " << damage << std::endl;
}

void Character::getMoney() {
    if (m_mediator != nullptr) {
        int s = m_mediator->takeScore();
        if (s > 0) {
            m_score += s;
            std::cout << "Character get score: " << s << std::endl;
        } else {
            std::cout << "No score to get." << std::endl;
        }
    }
}

void Character::getItem() {
    if (m_mediator != nullptr) {
        delete m_item;
        m_item = m_mediator->getItem(m_score);
        if (m_item != nullptr) {
            std::cout << "Character got an item!" << std::endl;
        }
    }
}

void Character::setMediator(Mediator* m) { m_mediator = m; }
