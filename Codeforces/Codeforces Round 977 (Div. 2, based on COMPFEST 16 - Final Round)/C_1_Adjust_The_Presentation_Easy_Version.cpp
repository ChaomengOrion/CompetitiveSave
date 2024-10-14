#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<int> start(N);
    for (int i = 0; i < N; i++) {
        std::cin >> start[i];
    }
    std::vector<int> sm;
    std::vector<bool> vis(N + 1, false);
    sm.reserve(N);
    for (int i = 0; i < M; i++) {
        int temp;
        std::cin >> temp;
        if (!vis[temp]) {
            vis[temp] = true;
            sm.push_back(temp);
        }
    }
    sm.shrink_to_fit();
    for (int i = 0; i < sm.size(); i++) {
        if (sm[i] != start[i]) {
            std::cout << "TIDAK" << std::endl;
            return;
        }
    }
    std::cout << "YA" << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}