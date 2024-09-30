#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int miles = -1;
    do {
        std::cout << "Enter miles driven (-1 to quit): ";
        if (miles == -1) break;
    } while (std::cin >> miles);
    return 0;
}