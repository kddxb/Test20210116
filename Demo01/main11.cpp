#include <iostream>
#include <array>
using namespace std;

namespace test11
{
    // arrayΪʲô���������ʼ��?
    // ���ǹ��캯�����ǽṹ���ʼ���ķ���
    void dotest()
    {
        std::array<int, 4> arr = { 1,2,3,4 };
        int (&a)[4] = arr._Elems;
        constexpr int size = arr.size();
        constexpr int max_size = arr.max_size();
    }
}