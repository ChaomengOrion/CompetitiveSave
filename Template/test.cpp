#include <bits/stdc++.h>

template<class T, class getFunc>
class ST {
private:
    std::vector<std::vector<T>> dp;
    getFunc get = getFunc();

public:
    ST(const std::vector<T>& inputs) {
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

    T query(size_t start, size_t end) {
        int exp = log2(end - start + 1);
        return get(dp[start][exp], dp[end - (1 << exp) + 1][exp]);
    }
};

int main() {
    struct GET {
        int operator()(int a, int b) {
            return std::min(a, b);
        }
    };
    ST<int, GET> st({12, 3, 4, -21, 2, 8});
    std::cout << st.query(0, 5) << std::endl;
}