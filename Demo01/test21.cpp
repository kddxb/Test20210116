#include <iostream>
using namespace std;

namespace test21
{
    void fun(int& i)
    {
        i += 100;
    }

    //���ű��ʽȡֵ���Բ�ͬ
    void dotest()
    {
        int i = 100;
        int j = (i++, fun(i), i);
        cout << "j = " << j << endl;
    }
}