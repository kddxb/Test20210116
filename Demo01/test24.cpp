#include <iostream>
using namespace std;

namespace test24
{

    struct A {};
    struct B :public A {};
    struct C {};

    template<typename T>
    void fun(std::enable_if_t<std::is_base_of_v<A, T>>* = nullptr)
    {
        std::cout << "is base of A" << std::endl;
    }

    template<typename T>
    void fun(std::enable_if_t<!std::is_base_of_v<A, T>>* = nullptr)
    {
        std::cout << "is't base of A" << std::endl;
    }

    template<typename T>
    std::enable_if_t<std::is_base_of_v<A, T>, int> fun2()
    {
        std::cout << "is base of A 222" << std::endl;
        return 0;
    }

    template<typename T>
    std::enable_if_t<!std::is_base_of_v<A, T>, int> fun2()
    {
        std::cout << "is't base of A 222" << std::endl;
        return 0;
    }

    //enable_if
    void dotest()
    {
        fun<A>();
        fun<B>();
        fun<C>();
        fun<int>();

        fun2<A>();
        fun2<B>();
        fun2<C>();
        fun2<int>();
    }
}