#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace test10
{
    class Class
    {
    public:
        Class()
        {
            students[0] = "AA";
            students[1] = "BB";
            students[2] = "CC";
            students[3] = "DD";
            students[4] = "EE";
        }

        std::string* begin()
        {
            return &students[0];
        }

        std::string* end()
        {
            return &students[5];
        }

    private:
        std::string students[5];
    };

    // 高级for循环遍历自定义类
    void dotest()
    {
        Class clazz;
        for (const std::string& name : clazz)
        {
            cout << name << endl;
        }
    }
}