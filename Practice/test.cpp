#include <bits/stdc++.h>

int test() {
    return 2;
}

int main() {
    int (*a)() = test;
    std::cout << (*a)() << std::endl;
    std::cout << a() << std::endl;
    std::cout << (&a)() << std::endl;
}