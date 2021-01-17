#include <iostream>
using namespace std;

namespace test01
{
    template<typename First, typename... Other>
    auto sum(First first, Other... other)
    {
        if constexpr (sizeof...(Other) > 0)
        {
            return first + sum(other...);
        }
        else
        {
            return first;
        }
    }

    // if constexpr
    void dotest()
    {
        cout << sum(1, 2, 3.5) << endl;
    }
}