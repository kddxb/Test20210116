#include <iostream>
using namespace std;

namespace test07
{
    struct A
    {
        void fun()const { cout << "A" << endl; }
    };

    struct B
    {
        const A* operator->()const { cout << "B" << endl; return ptr; }
        A* ptr = new A;
    };

    struct C
    {
        const B& operator->()const { cout << "C" << endl; return component; }
        B component;
    };

    struct D
    {
        const C& operator->()const { cout << "D" << endl; return component; }
        C component;
    };

    //箭头符号会一直作用下去，直到返回一个对象而不是指针为止
    void dotest()
    {
        D d;
        d->fun();
    }
}