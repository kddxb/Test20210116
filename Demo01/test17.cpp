#include <iostream>
using namespace std;

namespace test17
{

    //��������ִ�к���
    void dotest()
    {
        [](int i) {cout << i << endl; }(10);
        [] {cout << "hello" << endl; }();
    }
}