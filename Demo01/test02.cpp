#include <iostream>
using namespace std;

namespace test02
{
    struct X
    {
        int v;
        static int count;
        X() :v(count++) {}
        ~X()
        {
            cout << v << endl;
        }
    };

    int X::count = 0;

    // new[]必须与delete[]配对使用，不然析构函数只会被调用一次
    void dotest()
    {
        X* px = new X[3];
        delete[] px;
    }
}
