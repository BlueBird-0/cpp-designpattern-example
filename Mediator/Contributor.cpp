#include "Contributor.h"
#include "Mediator.h"

Contributor::Contributor() : m_mediator(nullptr) {
    for (int i = 0; i < 10; i++) {
        m_item[i] = nullptr;
    }
}

Item* Contributor::giveItem(int score) {
    if (score > 5) {
        return new Item{score, 10, 100};
    }
    return nullptr;
}

void Contributor::setMediator(Mediator* m) {
    m_mediator = m;
}
