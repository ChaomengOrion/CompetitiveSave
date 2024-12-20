#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<i64> A(N), B(M);
    i64 sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
        sumB += B[i];
    }
    std::vector<bool> Aset(2 * N + 1), Bset(2 * M + 1);
    for (int i = 0; i < N; i++) {
        if (abs(sumA - A[i]) > N) continue;
        Aset[sumA - A[i] + N] = true;
    }
    for (int i = 0; i < M; i++) {
        if (abs(sumB - B[i]) > M) continue;
        Bset[sumB - B[i] + M] = true;
    }
    while (Q--) {
        i64 X;
        std::cin >> X;
        bool ok = false;
        for (i64 i = 1; i * i <= abs(X); i++) {
            if (X % i) continue;
            i64 a = i;
            i64 b = X / i;
            if ((a <= N && abs(b) <= M && Aset[a + N] && Bset[b + M])
            || (abs(b) <= N && a <= M && Aset[b + N] && Bset[a + M])
            || (a <= N && abs(b) <= M && Aset[-a + N] && Bset[-b + M])
            || (abs(b) <= N && a <= M && Aset[-b + N] && Bset[-a + M])) {
                std::cout << "YES" << std::endl;
                ok = true;
                break;
            }
        }
        if (!ok) std::cout << "NO" << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}