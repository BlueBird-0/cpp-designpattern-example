#include <gtest/gtest.h>
#include "Proxy.cpp"

// 여기서 Proxy는 NewFactory를 사용하여 FirstFactory를 사용하고 있습니다.
TEST(ProxyTest, ProxyPatternTest) {
    MResultMatter resultMatter;
    NewFactory newFactory;
    string finalMatter = newFactory.process("A", resultMatter);
    cout << "name: " << resultMatter.name << endl;
    cout << "weight: " << resultMatter.weight << endl;
    cout << "finalMatter: " << finalMatter << endl;
}