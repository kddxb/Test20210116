//#include <iostream>
//using namespace std;
//
//template<typename First, typename... Other>
//auto sum(First first, Other... other)
//{
//    if constexpr (sizeof...(Other) > 0)
//    {
//        return first + sum(other...);
//    }
//    else
//    {
//        return first;
//    }
//}
//
//int main()
//{
//    cout << sum(1, 2, 3.5) << endl;
//
//    return 0;
//}