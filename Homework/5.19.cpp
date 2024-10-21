#include <bits/stdc++.h>

using u64 = unsigned long long;
using u32 = unsigned int;

int main()
{
    std::cin.sync_with_stdio(false);
    int N;
    std::cout << std::fixed << "Enter the N of terms you expect (-1 to quit): ";
    while (std::cin >> N) {
        if (N < 0) break;
        double ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += (i & 1 ? 1 : -1) * 4.0 / (2 * i - 1);
        }
        std::cout << "The value of PI is \033[1;36m"
                  << std::setprecision(9) << ans
                  << "\033[m\n\nEnter the N of terms you expect (-1 to quit): ";
    }
}