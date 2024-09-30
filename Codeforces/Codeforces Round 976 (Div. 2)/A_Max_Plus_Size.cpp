#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    int max = INT_MIN, max_i = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_i = i;
        }
        else if (arr[i] == max && max_i % 2 == 1)
        {
            max = arr[i];
            max_i = i;
        }
    }
    max_i++;
    if (n % 2 == 0)
    {
        std::cout << n / 2 + max << '\n';
    }
    else if (max_i % 2 == 0)
    {
        std::cout << (n - 1) / 2 + max << '\n';
    }
    else
    {
        std::cout << (n + 1) / 2 + max << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}