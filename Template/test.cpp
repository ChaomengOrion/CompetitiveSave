#include <bits/stdc++.h>

template<typename A>
void Print() {
    std::cerr << sizeof(A) << std::endl;
    std::clog << sizeof(A) << std::endl;
    assert(false);
}

int main() {
    int a = 3;
    std::cout << (++a)++ << std::endl;
    
}