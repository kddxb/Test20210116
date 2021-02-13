#include <iostream>
using namespace std;

namespace test18
{
    namespace t1
    {
        void fun()
        {
        }

        template<typename FIRST, typename... OTHERS>
        void fun(FIRST first, OTHERS... others)
        {
            std::cout << first << std::endl;
            fun(others...);
        }
    }

    namespace t2
    {
        template<typename T>
        void showArg(const T& t)
        {
            std::cout << t << std::endl;
        }

        template<typename... ARGS>
        void fun(ARGS... args)
        {
            int arr[] = { (showArg(args),0)... };
        }
    }

    namespace t3
    {
        template<typename T>
        int showArg(const T& t)
        {
            std::cout << t << std::endl;
            return 0;
        }

        template<typename... ARGS>
        void fun(ARGS... args)
        {
            //int arr[] = { showArg(args)... };
            std::initializer_list<int> list = { showArg(args)... };
        }
    }

    namespace t4
    {
        template<typename... ARGS>
        void fun(ARGS... args)
        {
            int arr[] = { ([&args]() {cout << args << endl; return 0; }())... };
        }
    }

    namespace t5
    {
        template<typename FIRST, typename... OTHERS>
        void fun(FIRST first, OTHERS... others)
        {
            std::cout << first << std::endl;
            if constexpr (sizeof...(OTHERS) > 0)
            {
                fun(others...);
            }
        }
    }

    namespace t6
    {
        template<typename... ARGS>
        void fun(ARGS... args)
        {
            int arr[] = { ([&args]() {cout << args << endl; return 0; }())... };
        }
    }

    namespace t7
    {
        template<typename... ARGS>
        void fun(ARGS... args)
        {
            (cout << ... << args) << endl;
        }
    }

    //可变参数模板展开
    void dotest()
    {
        t1::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$t1$$$$$$$$$" << std::endl;
        t2::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$t2$$$$$$$$$" << std::endl;
        t3::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$t3$$$$$$$$$" << std::endl;
        t4::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$t4$$$$$$$$$" << std::endl;
        t5::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$t5$$$$$$$$$" << std::endl;
        t6::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$$t6$$$$$$$$" << std::endl;
        t7::fun(1, "abc", 2, 3);
        std::cout << "$$$$$$$$$t7$$$$$$$$" << std::endl;
    }
}