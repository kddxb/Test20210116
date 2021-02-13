#include <iostream>
using namespace std;

namespace test16
{
    template<typename... ARGS>
    void fun(ARGS... args)
    {
        {
            auto temp = { args... };
            for (auto&& v : temp)
            {
                cout << v << endl;
            }
        }
        cout << "******************" << endl;
        {
            auto temp = { (args * args)... };
            for (auto&& v : temp)
            {
                cout << v << endl;
            }
        }
        cout << "******************" << endl;
        {
            auto temp = { (args * sin(args))... };
            for (auto&& v : temp)
            {
                cout << v << endl;
            }
        }
    }

    //测试可变模板参数
    void dotest()
    {
        fun(1, 2, 3, 4);
    }
}