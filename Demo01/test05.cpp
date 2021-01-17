#include <iostream>
using namespace std;

namespace test05
{
    int f(int i) { return i + 1; }
#define A(i) f(i+1)
#define B(i) A(i+2)
#define C(i) B(i+3)
#define D(i) C(i+4)

    // vs2019可以看到宏展开结果
    void dotest()
    {
        // 提示：扩展到:f(10+4+3+2+1)
        int v = D(10);
        cout << v << endl;
    }
}