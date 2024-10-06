#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size)                       \
    std::cerr << #vec << " = " << '[';        \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;

inline int fact(int n)
{
    if (n == 2) return 2;
    if (n == 3) return 6;
    if (n == 4) return 24;
    if (n == 5) return 120;
    if (n == 6) return 720;
    if (n == 7) return 5040;
    if (n == 8) return 40320;
    if (n == 9) return 362880;
    if (n == 10) return 3628800;
    return 1;
}

int all(std::string& s)
{
    std::vector<int> cnt(10);
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0']++;
    }
    int ans = fact(s.size());
    for (int i = 0; i < 10; i++) {
        ans /= fact(cnt[i]);
    }
    return ans;
}

int dp[1024][1000], num[10];

void solve()
{
    std::string source;
    std::cin >> source;
    int n = source.size();
    std::sort(source.begin(), source.end());

    int d;
    std::cin >> d;
    int cnt = 0;

    if (d == 1) {
        std::cout << all(source) << std::endl;
        return;
    }

    if (d % 3 == 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += source[i] - '0';
        }
        if (d == 3 && sum % 3 == 0) {
            std::cout << all(source) << std::endl;
            return;
        } else if (d == 3) {
            std::cout << 0 << std::endl;
            return;
        }
    }
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) num[source[i] ^ 48]++;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((1 << j) & ~i) continue;
            for (int k = 0; k < d; k++)
                dp[i][((k << 3) + (k << 1) + (source[j] ^ 48)) % d] += dp[i ^ (1 << j)][k];
        }
    }
    for (int i = 0; i < 10; i++) dp[(1 << n) - 1][0] /= fact(num[i]);
    std::cout << dp[(1 << n) - 1][0] << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}