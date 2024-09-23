#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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
            int ksq_half = 1 << (k - 1);
            for (size_t i = 0; (i + (1 << k)) <= len; i++) {
                dp[i][k] = get(dp[i][k - 1], dp[i + ksq_half][k - 1]);
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

void solve()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cows[i];
    }
    ST<int> maxST(cows, true), minST(cows, false);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        std::cout << maxST.query(l, r) - minST.query(l, r) << std::endl;
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