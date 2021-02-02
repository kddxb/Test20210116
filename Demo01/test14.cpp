#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace test14
{
    struct MyStruct
    {
        int i = 0;
        std::string s;
    };

    //结构化赋值
    void dotest()
    {
        MyStruct ms;
        auto [u, v] = ms;

        constexpr std::pair<int, int> p = std::make_pair(10, 20);
        auto [x, y] = p;
        x = 10;
        int s = 10;
        x = s;

        int&& z = 10;
        z = s;
    }
}