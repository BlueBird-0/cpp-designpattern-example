#include <gtest/gtest.h>
#include <iostream>
#include "Observer.cpp"

TEST(Observer, Main) {
    NewsPublisher publisher;
    AnnualSubscriber annualSubscriber;
    EventSubscriber eventSubscriber;

    // Observer 등록
    publisher.addObserver(annualSubscriber);
    publisher.addObserver(eventSubscriber);

    // 뉴스 정보 설정 및 알림
    publisher.setNewsInfo("Breaking News", "New C++ Standard Released");

    // 다시 뉴스 정보 설정 및 알림
    publisher.setNewsInfo("Update", "C++23 Features Announced");
}