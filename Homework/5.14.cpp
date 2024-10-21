#include <bits/stdc++.h>

using u64 = unsigned long long;
using u32 = unsigned int;

int main()
{
    int num, cnt;
    std::cin >> num >> cnt;
    double ans = 0;
    switch (num) {
        case 1:
            ans = 2.98;
            break;
        case 2:
            ans = 4.50;
            break;
        case 3:
            ans = 9.98;
            break;
        case 4:
            ans = 4.49;
            break;
        case 5:
            ans = 6.87;
            break;
    }
    std::cout << ans * cnt << std::endl;
}