#define testnamespace test20

namespace testnamespace
{
    extern void dotest();
}

int main()
{

    testnamespace::dotest();
    return 0;
}