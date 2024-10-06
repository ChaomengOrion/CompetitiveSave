#include <bits/stdc++.h>

int main() {
    int a = 1;
    int b = 2;
    int* ap = &a;
    int* bp = &b;
    int& ar = a;
    int& br = b;
    std::cout << *ap << " | " << *bp << std::endl;
    ar = 3, br = 4;
    std::cout << *ap << " | " << *bp << std::endl;
    std::swap(ar, br);
    ar = 3, br = 4;
    std::cout << *ap << " | " << *bp << std::endl;
}
