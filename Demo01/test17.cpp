#include <iostream>
using namespace std;

namespace test17
{

    //²âÊÔÁ¢¼´Ö´ĞĞº¯Êı
    void dotest()
    {
        [](int i) {cout << i << endl; }(10);
        [] {cout << "hello" << endl; }();
    }
}