#include <bits/stdc++.h>

int main()
{
    double M, N;
    while (std::cin >> M >> N) {
        double delta = N, height = 0;
        int day = 1;
        while (true) {
            height += delta;
            if (height >= M) {
                std::cout << day << std::endl;
                break;
            }
            height -= 1;
            day += 1;
            delta /= 3;
            if (delta <= 1) break;
        }
        if (height < M) {
            std::cout << "Never" << std::endl;
        }
    }
    return 0;
}