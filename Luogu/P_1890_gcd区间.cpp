#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;


template<typename T>
class ST {
private:
    std::vector<std::vector<T>> dp;
    T (*get) (T, T);

public:
    ST(const std::vector<T>& inputs, auto getFunc) {
        get = getFunc;
        size_t len = inputs.size();
        int exp = log2(len);
        // dp[i][k] 代表从i出发走2^k步内的最大值
        dp.resize(len, std::vector<T>(exp + 1, 0));
        for (size_t i = 0; i < len; i++) {
            dp[i][0] = inputs[i];
        }

        for (int k = 1; k <= exp; k++) {
            for (size_t i = 0; i + (1 << k) <= len; i++) {
                dp[i][k] = get(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T query(size_t start, size_t end) const {
        if (start > end) {
            throw std::invalid_argument("start should be less than or equal to end");
        }
        int exp = log2(end - start + 1);
        return get(dp[start][exp], dp[end - (1 << exp) + 1][exp]);
    }
};

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void solve()
{
    int n = read(), q = read();
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }

    ST<int> st(a, [](int x, int y) { return std::gcd(x, y); });

    while (q--) {
        int l = read(), r = read();
        l--; r--;
        std::cout << st.query(l, r) << '\n';
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