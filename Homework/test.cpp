#include <bits/stdc++.h>

int test(int a, int b = 555);

int test(int a, int b) {
    a--;
    return b;
}

int aaa(int a, int b );

int aaa(int a, int b = 555) {
    a--;
    return b;
}

int main() {
    std::cout << test(3, 35235) << std::endl;
    std::cout << test(3) << std::endl;
    std::cout << aaa(3, 35235) << std::endl;
    std::cout << aaa(3) << std::endl;
}