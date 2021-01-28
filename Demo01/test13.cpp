#include <iostream>
using namespace std;

#include <compare>

namespace test13
{
    struct MyInt {
        int value;
        MyInt(int value) : value{ value } { }
        auto operator<=>(const MyInt&) const = default;
    };

    void dotest()
    {
        MyInt i1 = 1;
        MyInt i2 = 2;
        bool b = i1 < i2;

    }
}