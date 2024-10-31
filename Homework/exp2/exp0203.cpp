#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    char cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << (char)(cnt + 'A');
            cnt = (cnt + 1) % 26;
        }
        std::cout << std::endl;
    }
}