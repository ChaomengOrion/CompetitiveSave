#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> mul(std::vector<int>& a, std::vector<int>& x) {
    std::vector<int> ret(a.size(), 0);
    for (int i = 1; i < a.size(); i++) ret[i] = a[x[i]];
    return ret;
}

// 🐔🐔🐔
void solve() {
    i64 N, K;
    std::cin >> N >> K;
    std::vector<int> X(N + 1), A(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> X[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }
    while (K) {
        if (K & 1) A = mul(A, X);
        X = mul(X, X);
        K >>= 1;
    }
    for (int i = 1; i <= N; i++) {
        std::cout << A[i] << ' ';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}