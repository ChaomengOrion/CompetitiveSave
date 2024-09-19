#include <bits/stdc++.h>

int main() {
    int a = 111;
    int& b = a;
    b = 222;
    std::cout << a << std::endl;
}