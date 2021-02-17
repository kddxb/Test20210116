#include <iostream>
using namespace std;

namespace test27
{
    template<typename T, typename... TS>
    struct IsIn {};

    template<typename T, typename First, typename... Others>
    struct IsIn<T, First, Others...>
    {
        constexpr static bool value = []() {
            if constexpr (std::is_same_v<T, First>)
            {
                return true;
            }
            if constexpr (sizeof...(Others) > 0)
            {
                return IsIn<T, Others...>::value;
            }
            return false;
        }();
    };

    template<typename T, typename... TS>
    constexpr static bool IsIn_v = IsIn<T, TS...>::value;

    //My IsIn #2
    void dotest()
    {
        constexpr bool is_in1 = IsIn_v<int, double, char>;
        constexpr bool is_in2 = IsIn_v<int, double, char, int>;
    }
}