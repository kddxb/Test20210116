#include <iostream>
#include <array>
using namespace std;

namespace test11
{
    // array为什么能用数组初始化?
    // 不是构造函数，是结构体初始化的方法
    void dotest()
    {
        std::array<int, 4> arr = { 1,2,3,4 };
        int (&a)[4] = arr._Elems;
        constexpr int size = arr.size();
        constexpr int max_size = arr.max_size();
    }
}