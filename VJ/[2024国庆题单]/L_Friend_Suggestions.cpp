#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> fa(N + 1);
    for (int i = 0; i <= N; i++) {
        fa[i] = i;
    }
    auto find = [&](auto&& find, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(find, fa[x]);
    };
    auto merge = [&](int a, int b) -> void {
        fa[find(find, a)] = fa[find(find, b)];
    };

    std::vector<std::unordered_set<int>> blocks(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        merge(a, b);
        blocks[a].insert(b);
        blocks[b].insert(a);
    }
    for (int i = 0; i < K; i++) {
        int a, b;
        std::cin >> a >> b;
        blocks[a].insert(b);
        blocks[b].insert(a);
    }

    std::vector<int> faCnt(N + 1, 0); // 并查集计数
    for (int i = 1; i <= N; i++) {
        faCnt[find(find, i)]++;
    }

    for (int i = 1; i <= N; i++) {
        int friendCnt = faCnt[find(find, i)] - 1;
        for (int f : blocks[i]) {
            if (fa[find(find, f)] == fa[find(find, i)]) {
                friendCnt--;
            }
        }
        std::cout << friendCnt << ' ';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}