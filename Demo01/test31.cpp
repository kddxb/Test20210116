#include <iostream>
using namespace std;

namespace test31
{

    template<typename T, typename... ARGS>
    constexpr static bool IsIn_v = ((std::is_same_v<ARGS, T>) || ...);

    template<typename T, typename... ARGS>
    constexpr bool IsIn_Fun()
    {
        constexpr bool sames[] = { std::is_same_v<ARGS, T>... };
        for (bool b : sames)
        {
            if (b)
            {
                return true;
            }
        }
        return false;
    }

    //My IsIn #5
    void dotest()
    {
        constexpr bool is_in1 = IsIn_v<int, double, char>;
        constexpr bool is_in2 = IsIn_v<int, double, char, int>;

        constexpr bool is_in3 = IsIn_Fun<int, double, char>();
        constexpr bool is_in4 = IsIn_Fun<int, double, char, int>();
    }
}