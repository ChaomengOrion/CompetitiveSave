#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N);
    std::vector<int> b(M);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> b[i];
    }
    std::vector<i64> pre(N + 1);
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    std::vector<std::pair<int, int>> lim;
    int lastV = -1;
    for (int i = M - 1; i >= 0; i--) {
        if (b[i] > lastV) {
            lim.emplace_back(b[i], M - (1 + i));
            lastV = b[i];
        }
    }

    int lpos = 0;
    
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}