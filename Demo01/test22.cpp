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
        //����#1ƥ��ʱ��int::type��������SFINAE�����Ի����ƥ����ȥ��ƥ�䵽#2
        fun(0);
    }
}