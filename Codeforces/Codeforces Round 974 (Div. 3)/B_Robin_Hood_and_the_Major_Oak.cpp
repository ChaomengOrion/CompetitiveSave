#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, k; // 要求的年份和树叶保留的年数
    std::cin >> n >> k;
    int flag;
    int start = n - k + 1, end = n;
    // 判断start到end间有多少个奇数
    if (start & 1 ^ 1 && end & 1 ^ 1) {
        flag = (end - start) / 2;
    }
    else
    {
        flag = (end - start) / 2 + 1;
    }
    std::cout << (flag & 1 ^ 1 ? "YES" : "NO") << std::endl;
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