#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const i64 MOD = 998244353;

struct node {
    i64 val;
    int index;
    bool operator<(const node& other) const {
        return val < other.val;
    }
    bool operator<=(const node& other) const {
        return val <= other.val;
    }
};

i64 binpow(i64 a, i64 b) {
    a %= MOD;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

i64 divmod(i64 a, i64 b) { // a / b % mod
    return a * binpow(b, MOD - 2) % MOD;
}

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<node> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) {
        A[i].index = i;
        std::cin >> A[i].val;
    }
    for (int i = 1; i <= N; i++) {
        B[i].index = i;
        std::cin >> B[i].val;
    }
    std::sort(A.begin() + 1, A.end());
    std::sort(B.begin() + 1, B.end());
    std::vector<int> o2n_A(N + 1), o2n_B(N + 1);
    for (int i = 1; i <= N; i++) {
        o2n_A[A[i].index] = i;
        o2n_B[B[i].index] = i;
    }
    i64 mul = 1;
    std::vector<int> minv(N + 1);
    for (int i = 1; i <= N; i++) {
        minv[i] = std::min(A[i].val, B[i].val);
        mul *= minv[i] % MOD;
        mul %= MOD;
    }
    std::cout << mul << ' ';

    auto update = [&](int newi) -> void {
        int v = std::min(A[newi].val, B[newi].val);
        if (v == minv[newi]) { //* 无更新

        } else { //! 更新
            mul = divmod(mul, minv[newi]);
            mul *= v % MOD;
            mul %= MOD;
            minv[newi] = v;
        }
    };

    auto modify = [&](int index, std::vector<node>& soruce, std::vector<int>& o2n) -> void {
            int newi = o2n[index];

            auto last_it = prev(std::upper_bound(soruce.begin(), soruce.end(), soruce[newi]));
            int lasti = last_it - soruce.begin();
            o2n[index] = lasti;
            o2n[soruce[lasti].index] = newi;
            std::swap(soruce[newi], soruce[lasti]);
            soruce[lasti].val++;

            update(newi);
            update(lasti);
    };

    while (Q--) {
        int op, index;
        std::cin >> op >> index;
        if (op == 1) {
            modify(index, A, o2n_A);
        } else {
            modify(index, B, o2n_B);
        }
        std::cout << mul << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}