#pragma once
#include "Item.h"

class Mediator;

class Contributor {
public:
    Item* m_item[10];
    Mediator* m_mediator;

    Contributor();
    Item* giveItem(int score);
    void setMediator(Mediator* m);
};
