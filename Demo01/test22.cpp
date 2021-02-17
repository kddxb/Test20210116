#include <iostream>
using namespace std;

namespace test22
{
    struct Test { using type = int; };

    //#1
    template<typename T>
    void fun(typename T::type)
    {
        std::cout << "has type" << std::endl;
    }

    //#2
    template<typename T>
    void fun(T)
    {
        std::cout << "no type" << std::endl;
    }

    //SFINAE
    //Substitution failure is not an error
    void dotest()
    {
        fun<Test>(0);
        //当与#1匹配时，int::type报错，但是SFINAE，所以会继续匹配下去，匹配到#2
        fun(0);
    }
}