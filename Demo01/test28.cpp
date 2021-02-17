#include <iostream>
using namespace std;

namespace test28
{

    template<typename T, typename... ARGS>
    struct IsIn
    {
        constexpr static bool value = ((std::is_same_v<ARGS, T>) || ...);
    };

    template<typename T, typename... TS>
    constexpr static bool IsIn_v = IsIn<T, TS...>::value;

    //My IsIn #3
    void dotest()
    {
        constexpr bool is_in1 = IsIn_v<int, double, char>;
        constexpr bool is_in2 = IsIn_v<int, double, char, int>;
    }
}