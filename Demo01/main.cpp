#define testnamespace test11

namespace testnamespace
{
    extern void dotest();
}

int main()
{

    testnamespace::dotest();
    return 0;
}