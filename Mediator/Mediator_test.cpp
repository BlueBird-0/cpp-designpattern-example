#include <gtest/gtest.h>
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Contributor.h"
#include "Mediator.h"

TEST(Mediator, MediatorPattern) {
    Character ch;
    Monster m;
    Contributor ct;

    Mediator mediator(&ch, &m, &ct);

    ch.setMediator(&mediator);
    m.setMediator(&mediator);
    ct.setMediator(&mediator);

    ch.attack();    //캐릭터가 attack할경우, mediator에 등록된 monster를 공격합니다.
    m.attack();     //몬스터가 attack할경우, character를 공격합니다.
    ch.attack();    //캐릭터가 attack할경우, mediator에 등록된 monster를 공격합니다.
    std::cout << "------------------" << std::endl;

    ch.getMoney();
    ch.getItem();
}