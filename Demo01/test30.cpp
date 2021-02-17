#include <iostream>
using namespace std;

namespace test30
{
    ////不可以特化
    //template<typename P, typename Q>
    //using type = int;

    //template<typename T>
    //using type<T, T> = double;

    template<typename P, typename Q>
    constexpr bool value = false;

    template<typename T>
    constexpr bool value<T, T> = true;

    void dotest()
    {
        //using type1 = type<int, double>;
        //using type2 = type<int, int>;

        constexpr bool value1 = value<int, double>;
        constexpr bool value2 = value<int, int>;
    }
}