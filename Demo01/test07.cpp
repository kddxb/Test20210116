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

    //��ͷ���Ż�һֱ������ȥ��ֱ������һ�����������ָ��Ϊֹ
    void dotest()
    {
        D d;
        d->fun();
    }
}