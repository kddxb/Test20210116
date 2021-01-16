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
    //new[]������delete[]���ʹ�ã���Ȼ��������ֻ�ᱻ����һ��
    delete[] px;

    return 0;
}