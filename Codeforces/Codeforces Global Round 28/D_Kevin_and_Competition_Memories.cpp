#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 N, M;
    std::cin >> N >> M;
    std::vector<i64> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    std::sort(A.begin() + 1, A.end());
    std::sort(B.begin(), B.end());
    int can = std::upper_bound(B.begin(), B.end(), A[0]) - B.begin();
    std::vector<i64> cnts(M);
    for (int i = 0; i < M; i++) {
        cnts[i] = A.end() - std::lower_bound(A.begin() + 1, A.end(), B[i]);
    }
    for (int K = 1; K <= M; K++) {
        i64 ans = 0;
        ans += can / K;
        
        int low = M - K;
        low += can % K;
        
        for (; low >= can; low -= K) {
            ans += cnts[low] + 1;
        }
        std::cout << ans << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}