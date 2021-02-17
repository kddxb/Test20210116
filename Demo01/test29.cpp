#include <iostream>
using namespace std;

namespace test29
{

    template<typename T, typename... ARGS>
    constexpr static bool IsIn_v = ((std::is_same_v<ARGS, T>) || ...);

    //My IsIn #4
    void dotest()
    {
        constexpr bool is_in1 = IsIn_v<int, double, char>;
        constexpr bool is_in2 = IsIn_v<int, double, char, int>;
    }
}