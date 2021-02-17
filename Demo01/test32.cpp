#include <iostream>
#include <functional>
using namespace std;

namespace test32
{

    struct A
    {
        int v = 100;
        A(int v) :v(v) { cout << "构造函数 0x" << this << endl; }
        A(const A& other) { v = other.v; cout << "拷贝构造函数 from 0x" << &other << " to 0x" << this << endl; }
        A& operator=(const A& other) { v = other.v; cout << "拷贝赋值运算符 from 0x" << &other << " to 0x" << this << endl; return *this; }
        ~A() { cout << "析构函数 0x" << this << endl; }
    };


    void dotest()
    {
        //{
        //    A info = 1;
        //    cout << "1111111111" << endl;
        //    std::function<const A& ()> func = [info]() {cout << "return @0x" << &info << endl; return info; };
        //    cout << "2222222222" << endl;
        //    const A& xx = func().v;
        //    cout << "3333333333" << endl;
        //    info.v = 2;
        //    cout << "4444444444" << endl;
        //    const A& yy = func().v;
        //}
        //cout << "##################" << endl;
        {
            A info = 1;
            cout << "1111111111" << endl;
            std::function<const A& ()> func = [&info]()->const A& {cout << "return @0x" << &info << endl; return info; };
            cout << "2222222222" << endl;
            func().v;
            cout << "3333333333" << endl;
            info.v = 2;
            cout << "4444444444" << endl;
            func().v;

            //lambda表达式默认返回值类型
            auto ff = [&info]() {return info; };
            using T = decltype(ff()); //T = A

        }

        {
            std::string info = "1";
            cout << "info @0x" << &info << endl;
            cout << "1111111111" << endl;

            //lambda表达式默认返回值类型，但是function返回引用类型，导致了返回一个局部变量的引用
            std::function<const std::string& ()> func = [&info]()->const std::string& {
                cout << "return @0x" << &info << endl;
                return info;
            };

            cout << "2222222222" << endl;
            cout << func() << endl;
            //std::string s1 = func();
            cout << "3333333333" << endl;
            info = "2";
            cout << "4444444444" << endl;
            cout << func() << endl;
            //std::string s2 = func();
        }

    }
}