#include <iostream>
using namespace std;

namespace test26
{
    template<typename T, typename... TS>
    struct IsIn {};

    template<typename T>
    struct IsIn<T>
    {
        constexpr static bool value = false;
    };

    template<typename T, typename First, typename... Others>
    struct IsIn<T, First, Others...>
    {
        constexpr static bool value = std::is_same_v<T, First> || IsIn<T, Others...>::value;
    };

    template<typename T, typename... TS>
    constexpr static bool IsIn_v = IsIn<T, TS...>::value;

    //My IsIn #1
    void dotest()
    {
        constexpr bool is_in1 = IsIn_v<int, double, char>;
        constexpr bool is_in2 = IsIn_v<int, double, char, int>;
    }
}