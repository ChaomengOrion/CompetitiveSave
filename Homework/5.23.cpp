#include <bits/stdc++.h>

using i64 = long long;

int main(){
    int N = 10;
    std::cout << "          *\n";
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (j >= i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << '*';
        for (int j = 0; j < N; j++) {
            if (N - j > i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << '*';
        for (int j = 0; j < N; j++) {
            if (N - j > i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "          *\n";
}