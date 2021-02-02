#include <iostream>
using namespace std;

namespace test15
{
    template<typename T1, typename T2>
    struct X
    {
        template<typename P, typename Q>
        X(P, Q)
        {
        }

        void fun()
        {
            cout << typeid(T1).name() << "," << typeid(T2).name() << endl;
        }
    };

    template<typename P, typename Q>
    X(P, Q)->X<P, Q>;

    template<typename P,typename Q>
    X(P*, Q*)->X<double, double>;

    X(bool, bool)->X<int,int>;

    //模板类自动类型推导
    void dotest()
    {
        X x1(1, 1.0);
        x1.fun();

        int* pi = nullptr;
        int* pd = nullptr;
        X x2(pi, pd);
        x2.fun();

        X x3(true, false);
        x3.fun();
    }
}