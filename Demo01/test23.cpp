#include <iostream>
using namespace std;

namespace test23
{

    struct A {};
    struct B :public A {};
    struct C {};

    template<typename T>
    std::enable_if_t<std::is_base_of_v<A, T>> fun()
    {
        std::cout << "is base of A" << std::endl;
    }

    template<typename T>
    std::enable_if_t<!std::is_base_of_v<A, T>> fun()
    {
        std::cout << "is't base of A" << std::endl;
    }

    //SFINAE
    //Substitution failure is not an error
    void dotest()
    {
        fun<B>();//ʵ����������void fun<B>();
        fun<C>();//ʵ����������void fun<C>();
        fun<int>();//ʵ����������void fun<int>();
    }
}