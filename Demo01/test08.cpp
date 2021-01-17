#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace test08
{
    //这种不是模板模板参数
    template<typename T, typename Q = std::vector<T>>
    struct MyStruct1
    {
        using type1 = T;
        using type2 = Q;
    };

    template<typename T, 
        template<typename> typename Container>
    struct MyStruct2
    {
        using type = Container<T>;
    };

    template<typename T,
        template<typename, typename> typename Container>
    struct MyStruct3
    {
        using type = Container<T,T>;
    };


    // 模板模板参数 template template parameter
    void dotest()
    {
        {
            using type1 = MyStruct1<int>::type1;
            using type2 = MyStruct1<int>::type2;
        }

        {
            using type1 = MyStruct1<int, double>::type1;
            using type2 = MyStruct1<int, double>::type2;
        }

        {
            using type = MyStruct2<int, std::vector>::type;
        }

        {
            using type = MyStruct3<int, std::map>::type;
        }

    }
}