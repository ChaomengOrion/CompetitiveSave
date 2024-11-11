#include <bits/stdc++.h>

void test() {
    return;
}

void foo() {
    return;
}

int main()
{
    test();
    (*test)();
    (*&test)();
    (&*test)();
    (&test)();
    (**********test)();
    
    
    void (*a)()  = foo;
    a();
    (*a)();
    (*&a)();
    (&*a)();
    //(&a)();
    (**********a)();
}