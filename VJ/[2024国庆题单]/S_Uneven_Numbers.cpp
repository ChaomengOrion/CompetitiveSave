#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

int getd(int n) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n /= 10;
    }
    return ans;
}

void solve()
{
    int N;
    std::cin >> N;
    int n = 1, rest = N, cnt = 0;
    while (n <= N) {
        if (getd(n) & 1) {
            cnt += std::min(9 * n, rest);
        }
        rest -= 9 * n;
        n *= 10;
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}