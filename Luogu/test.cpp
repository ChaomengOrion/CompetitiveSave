#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template <class T, class Merge = std::plus<T>>
struct BIT {
    const Merge merge;
    std::vector<T> t;

    BIT(int n) : t(n + 1), merge(Merge()) {}

    // O(n) build BIT
    BIT(const std::vector<T>& a) : BIT(a.size()) {
        int n = a.size();
        for (int i = 1; i <= n; i++) {
            t[i] = merge(t[i], a[i - 1]);
            int j = i + (i & -i);
            if (j <= n)
                t[j] = merge(t[j], t[i]);
        }
    }

    void add(int i, const T &x) {
        for (i += 1; i < t.size(); i += i & -i)
            t[i] = merge(t[i], x);
    }

    T posQuery(int i)  {
        T res = T();
        for (i += 1; i; i -= i & -i)
            res = merge(res, t[i]);
        return res;
    }

    T rangeQuery(int l, int r)  { // [l, r]
        return posQuery(r) - posQuery(l - 1);
    }
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int max = 100;
    BIT<int> bit(max);
    i64 sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        bit.add(arr[i], 1);
        sum += bit.rangeQuery(0, arr[i] - 1);
    }
    std::cout << sum << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}