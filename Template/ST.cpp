#include <bits/stdc++.h>

template<typename T>
class ST {
private:
    std::vector<std::vector<T>> dp;
    bool isMax;
    const T& (*get) (const T&, const T&);

public:
    ST(const std::vector<T>& inputs, bool isMax = true)
        : isMax(isMax) {
        if (isMax) get = std::max;
        else get = std::min;
        size_t len = inputs.size();
        int exp = log2(len);
        // dp[i][k] 代表从i出发走2^k步内的最大值
        dp.resize(len, std::vector<T>(exp + 1, 0));
        for (size_t i = 0; i < len; i++) {
            dp[i][0] = inputs[i];
        }

        for (int k = 1; k <= exp; k++) {
            for (size_t i = 0; (i + (1 << k)) <= len; i++) {
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

    T query_o(size_t start, size_t end) const {
        if (start > end) {
            throw std::invalid_argument("start should be less than or equal to end");
        }
        size_t pos = start;
        int exp = log2(end - start + 1);
        T V = isMax ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max();
        for (int k = exp; k >= 0; k--) {
            if (pos + (1 << k) > end + 1) continue; 
            V = get(V, dp[pos][k]);
            pos += 1 << k;
        }
        assert(pos > end);
        return V;
    }
};