#include <iostream>
using namespace std;

namespace test04
{
    //#�Ĺ����ǽ������ĺ���������ַ�����������Stringfication������˵�����ڶ��������õĺ����ͨ���滻���������Ҹ�����һ��˫����
#define STR(str) #str
#define WSTR(str) L#str
#define STR2(str1, str2) #str1" VS "#str2

    //##���ӷ����书�����ڴ������ĺ궨���н������Ӵ�(token)�����������Ӷ��γ�һ���µ��Ӵ�����##������ڵ�ǰ�������Ӵ���������������##��ǰ����������һ���Ӵ�����n��##���ӷ�����n + 1���Ӵ�
#define NAME(name,INDEX) name##INDEX

    // ��չ��
    void dotest()
    {
        constexpr const char* c1 = STR(hello);// "hello"
        constexpr const wchar_t* c2 = WSTR(hello);// L"hello"
        constexpr const char* c3 = STR2(hello, world);// "hello VS world"

        int NAME(i,1) = 10;
    }
}