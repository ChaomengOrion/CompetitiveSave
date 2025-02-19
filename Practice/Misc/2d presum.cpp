#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int h, w;
    std::cin >> h >> w;
    std::vector pre(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> pre[i][j];
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            // 加上、左，减左上
        }
    }

    auto query = [&](int rs, int cs, int re, int ce) -> int {
        return pre[re][ce] - pre[re][cs - 1] - pre[rs - 1][ce] + pre[rs - 1][cs - 1];
        // 减上、左，加左上
    };

    std::cout << query(2, 2, 3, 3) << std::endl; // 16
    std::cout << query(2, 3, 3, 3) << std::endl; // 10
    std::cout << query(1, 1, 3, 4) << std::endl; // 22 
    
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}