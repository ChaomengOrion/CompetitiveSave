#include <bits/stdc++.h>

int age = 0;

void add(int x) {
    age = age + x;
}

int f(int k, int x, int b) {
    return k * x + b;
}

// f(k, x, b) = kx + b

int main()
{
    add(111);
    add(222);
    std::cout << age << std::endl;
}