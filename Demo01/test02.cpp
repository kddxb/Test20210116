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

    // new[]������delete[]���ʹ�ã���Ȼ��������ֻ�ᱻ����һ��
    void dotest()
    {
        X* px = new X[3];
        delete[] px;
    }
}
