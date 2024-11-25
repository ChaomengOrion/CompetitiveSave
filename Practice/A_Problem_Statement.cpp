#include <bits/stdc++.h>

int main() {
    *std::ostream_iterator<int>(std::cout, nullptr) = *std::istream_iterator<int>(std::cin) - 1;
}