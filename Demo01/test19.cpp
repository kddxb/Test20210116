#include <iostream>
using namespace std;

namespace test19
{
    template<typename... ARGS>
    auto sum(ARGS... args)
    {
        //С���Ų���ʡ��
        return (args + ...);
    }

    //fold expression
    void dotest()
    {
        cout << sum(1, 2, 3.5) << endl;
    }
}