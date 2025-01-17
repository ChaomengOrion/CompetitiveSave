#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

template<typename T> class TreeArray {
private:
    int size;
    std::vector<T> arr;

public:
    TreeArray(int len)
        : size(len)
        , arr(len + 1, 0) {}

    TreeArray(std::vector<T>& source)
        : size(source.size())
        , arr(size + 1, 0) {
        for (int i = 1; i <= size; i++) {
            add(i, source[i]);
        }
    }

    inline static int lowbit(int x) { return x & -x; }

    void add(int pos, T value) {
        while (pos <= size) {
            arr[pos] += value;
            pos += lowbit(pos);
        }
    }

    i64 query(int pos) {
        i64 sum = 0;
        while (pos >= 1) {
            sum += arr[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }

    i64 query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    TreeArray<i64> bit(N);
    while (Q--) {
        char t; int p, x;
        std::cin >> t >> p >> x;
        if (t == 'x') {
            bit.add(p, x);
        } else {
            std::cout << bit.query(p, x) << std::endl;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}