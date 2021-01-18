#include <iostream>
using namespace std;

namespace test09
{
    constexpr int fun(int n)
    {
        int r = 1;
        for (int i = 1; i <= n; i++)
        {
            r *= i;
        }
        return r;
    }

    template<int n, typename = std::enable_if_t<n >= 1>>
    struct Fun
    {
        static const int i = Fun<n - 1>::i * n;
    };

    template<>
    struct Fun<1>
    {
        static const int i = 1;
    };


    template<int n, typename = std::enable_if_t<n >= 1>>
    struct Fun2
    {
        static constexpr int GetI()
        {
            if constexpr (n > 1)
            {
                return Fun<n - 1>::i * n;
            }
            else
            {
                return 1;
            }
        }

        static const int i = GetI();
    };

    //编译期计算阶乘的方式
    void dotest()
    {
        constexpr int r1 = fun(5);
        constexpr int r2 = Fun<5>::i;
        constexpr int r3 = Fun2<5>::i;
    }
}