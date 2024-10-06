#include <bits/stdc++.h>

using u64 = unsigned long long;
using u32 = unsigned int;

u64 fact(u32 x)
{
    u64 ans = 1;
    for (u32 i = x; i > 1; i--) ans *= i;
    return ans;
}

double binpow(double a, u32 b)
{
    if (b == 0) return 1;
    double res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
    std::cin.sync_with_stdio(false);
    int N;
    std::cout << std::fixed << "Enter the N of terms you expect (-1 to quit): ";
    while (std::cin >> N) {
        if (N < 0) break;
        std::cout << "Enter the value of x: ";
        double x;
        std::cin >> x;
        double ans = 0;
        for (int i = 0; i < N; i++) {
            ans += binpow(x, i) / fact(i);
        }
        std::cout << "The value of e^" << std::setprecision(3) << x << " is \033[1;36m"
                  << std::setprecision(9) << ans
                  << "\033[m\n\nEnter the N of terms you expect (-1 to quit): ";
    }
}