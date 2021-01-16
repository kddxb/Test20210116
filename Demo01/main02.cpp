#include <iostream>
using namespace std;

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

int main()
{
    X* px = new X[3];
    //new[]必须与delete[]配对使用，不然析构函数只会被调用一次
    delete[] px;

    return 0;
}