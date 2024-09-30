#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    i64 n, k;
    std::cin >> n >> k; // 不同类型纸牌的数量和硬币的数量
    std::vector<i64> arr(n + 1, 0); // the number of cards of type i you have at the beginning, for each 1≤i≤n
    i64 sum = 0;
    for (i64 i = 1; i <= n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    i64 max = *max_element(arr.begin(), arr.end());
    auto check = [&](i64 num) -> bool { // max每堆牌最多的牌数
        i64 need = std::max(max * num, (sum + num - 1) / num * num);
        return need - sum <= k;
    };

    int i = n;
    for (; i >= 0; i--) {
        if (check(i)) break;
    }
    std::cout << i << std::endl;
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