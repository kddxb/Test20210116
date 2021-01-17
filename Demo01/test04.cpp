#include <iostream>
using namespace std;

namespace test04
{
    //#的功能是将其后面的宏参数进行字符串化操作（Stringfication），简单说就是在对它所引用的宏变量通过替换后在其左右各加上一个双引号
#define STR(str) #str
#define WSTR(str) L#str
#define STR2(str1, str2) #str1" VS "#str2

    //##连接符号其功能是在带参数的宏定义中将两个子串(token)联接起来，从而形成一个新的子串，即##将其紧邻的前后两个子串联接起来。所以##的前后各必须存在一个子串，即n个##连接符连接n + 1个子串
#define NAME(name,INDEX) name##INDEX

    // 宏展开
    void dotest()
    {
        constexpr const char* c1 = STR(hello);// "hello"
        constexpr const wchar_t* c2 = WSTR(hello);// L"hello"
        constexpr const char* c3 = STR2(hello, world);// "hello VS world"

        int NAME(i,1) = 10;
    }
}