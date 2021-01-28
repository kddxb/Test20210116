#include <iostream>
#include <vector>
using namespace std;

namespace test12
{
    int fun1(int n) { return n + 1; }
    constexpr int fun2(int n) { return n + 1; }
    consteval int fun3(int n) { return n + 1; }

    void dotest()
    {
        int i = 0;
        constexpr int j = 0;
        fun1(i);
        fun1(j);
        fun2(i);
        fun2(j);
        //fun3(i); //consteval必须能编译器求值
        constexpr int xx = fun3(j);

    }
}