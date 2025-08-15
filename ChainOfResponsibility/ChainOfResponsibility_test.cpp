#include <gtest/gtest.h>
#include "ChainOfResponsibility.cpp"

TEST(ChainOfResponsibilityTest, TestHandlerA) {
    SpecificDepartmentAnswer* specificDepartmentAnswer = new SpecificDepartmentAnswer("Specific Department");
    InternetAnswer* internetAnswer = new InternetAnswer(specificDepartmentAnswer);

    internetAnswer->handleAsk(); // 인터넷 부서에 질문을 합니다.
    // 인터넷 부서가 답변을 처리하지 못하면, 다음 부서로 넘어갑니다.
}