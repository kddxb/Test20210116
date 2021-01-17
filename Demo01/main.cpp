#define testnamespace test07

namespace testnamespace
{
    extern void dotest();
}

int main()
{

    testnamespace::dotest();
    return 0;
}