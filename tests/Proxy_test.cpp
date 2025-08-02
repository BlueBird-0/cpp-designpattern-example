#include <gtest/gtest.h>
#include "../Proxy.cpp"

// 여기서 Proxy는 NewFactory를 사용하여 FirstFactory를 사용하고 있습니다.
TEST(AdditionTest, ProxyPatternTest) {
    MResultMatter resultMatter;
    NewFactory newFactory;
    string finalMatter = newFactory.process("A", resultMatter);
    cout << "name: " << resultMatter.name << endl;
    cout << "weight: " << resultMatter.weight << endl;
    cout << "finalMatter: " << finalMatter << endl;
}

// gtest_main 라이브러리를 링크하면 main 함수가 자동으로 제공되므로,
// 별도의 main 함수를 작성할 필요가 없습니다.