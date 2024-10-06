#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> fa(N + 1);
    for (int i = 0; i <= N; i++) {
        fa[i] = i;
    }
    auto find = [&](auto&& find, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(find, fa[x]);
    };

    while (M--) {
        int Z, X, Y;
        std::cin >> Z >> X >> Y;
        if (Z == 1) {
            fa[find(find, Y)] = fa[find(find, X)];
        } else if (Z == 2) {
            std::cout << (fa[find(find, Y)] == fa[find(find, X)] ? 'Y' : 'N') << std::endl;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}