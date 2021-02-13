#include <iostream>
using namespace std;

namespace test21
{
    void fun(int& i)
    {
        i += 100;
    }

    //逗号表达式取值可以不同
    void dotest()
    {
        int i = 100;
        int j = (i++, fun(i), i);
        cout << "j = " << j << endl;
    }
}