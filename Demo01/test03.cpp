#include <iostream>
#include <vector>
using namespace std;

namespace test03
{
    template<typename T = int>
    using MyVector = std::vector<T>;

    template<typename T = int>
    struct MyStruct
    {
        T t;
    };

    void dotest()
    {
        MyVector<int> v1;
        MyVector<> v2;
        //MyVector v3;
        MyStruct<int> s1;
        MyStruct<> s2;
        MyStruct s3;
    }
}