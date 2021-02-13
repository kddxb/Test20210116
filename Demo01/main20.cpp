#include <iostream>
using namespace std;

namespace test20
{
    class Int
    {
    public:
        Int(int v) :v(v) {}

        operator int()const
        {
            return v;
        }

        friend Int operator+(const Int& left, const Int& right)
        {
            cout << left.v << "+" << right.v << "=" << left.v + right.v << endl;
            return Int(left.v + right.v);
        }


    private:
        int v;
    };

    //һԪ���۵�
    template<typename... ARGS>
    auto sumRight(ARGS... args)
    {
        //С���Ų���ʡ��
        return (args + ...);
    }

    //һԪ���۵�
    template<typename... ARGS>
    auto sumLeft(ARGS... args)
    {
        //С���Ų���ʡ��
        return (... + args);
    }

    //��Ԫ���۵�
    template<typename... ARGS>
    auto sumRight2(ARGS... args)
    {
        //С���Ų���ʡ��
        return (args + ... + Int(100));
    }

    //��Ԫ���۵�
    template<typename... ARGS>
    auto sumLeft2(ARGS... args)
    {
        //С���Ų���ʡ��
        return (Int(100) + ... + args);
    }

    //fold expression
    void dotest()
    {
        {
            int res = sumRight(Int(1), Int(2), Int(3), Int(4));
            cout << "res = " << res << endl;
        }
        {
            int res = sumLeft(Int(1), Int(2), Int(3), Int(4));
            cout << "res = " << res << endl;
        }
        {
            int res = sumRight2(Int(1), Int(2), Int(3), Int(4));
            cout << "res = " << res << endl;
        }
        {
            int res = sumLeft2(Int(1), Int(2), Int(3), Int(4));
            cout << "res = " << res << endl;
        }
    }
}