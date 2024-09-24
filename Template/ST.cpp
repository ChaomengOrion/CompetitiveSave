#include <bits/stdc++.h>

template<typename T>
class ST {
private:
    std::vector<std::vector<T>> dp;
    T (*get) (T, T);
// [](int x, int y) { return std::gcd(x, y); }
// [](int x, int y) { return std::max(x, y); }
// [](int x, int y) { return std::min(x, y); }
public:
    ST(const std::vector<T>& inputs, auto getFunc) {
        get = getFunc;
        size_t len = inputs.size();
        int exp = log2(len);
        // dp[s][k] 代表从s出发走2^k步内的最值
        dp.resize(len, std::vector<T>(exp + 1, 0));
        for (size_t s = 0; s < len; s++) {
            dp[s][0] = inputs[s];
        }

        for (int k = 1; k <= exp; k++) {
            for (size_t s = 0; s + (1 << k) <= len; s++) {
                dp[s][k] = get(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T query(size_t start, size_t end) const {
        if (start > end) throw std::invalid_argument("start should be less than or equal to end");
        int exp = log2(end - start + 1);
        return get(dp[start][exp], dp[end - (1 << exp) + 1][exp]);
    }
};