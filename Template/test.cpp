#include <bits/stdc++.h>

#define LOGV(_vec, _size)\
    std::cerr << #_vec << " = " << '[';\
    for (int _i = 0; _i < (_size); _i++) {\
        std::cerr << (_vec)[_i];\
        if (_i != (_size) - 1) std::cerr << ",";\
    }\
    std::cerr << ']' << std::endl;

template<typename A>
void Print() {
    std::cerr << sizeof(A) << std::endl;
    std::clog << sizeof(A) << std::endl;
    assert(false);
}

int main() {

    int a = 3;
    std::cin >> a;
    std::vector<int> b(a);
    std::cout << (++a)++ << std::endl;
    LOGV(b, 3)
    std::cout << INT_MAX + INT_MAX + INT_MAX + 3 * INT_MAX << std::endl;
    std::cout << "END" << std::endl;
}