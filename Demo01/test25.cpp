#include <iostream>
using namespace std;

namespace test25
{
    template<typename P, typename Q>
    struct IsSame
    {
        constexpr static bool value = false;
    };

    template<typename T>
    struct IsSame<T, T>
    {
        constexpr static bool value = true;
    };

    template<typename P, typename Q>
    constexpr static bool IsSame_v = IsSame<P, Q>::value;

    //My IsSame
    void dotest()
    {
        constexpr bool is_same1 = IsSame_v<int, int>;
        constexpr bool is_same2 = IsSame_v<int, double>;
    }
}