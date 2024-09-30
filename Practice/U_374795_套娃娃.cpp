#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int h, w, S; // h <= 30
    std::cin >> h >> w >> S;
    std::vector cnts(h + 1, std::vector<int>(w + 1, 0));
    std::vector values(h + 1, std::vector<int>(w + 1, 0));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> cnts[i][j];
            cnts[i][j] += cnts[i - 1][j] + cnts[i][j - 1] - cnts[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> values[i][j];
            values[i][j] += values[i - 1][j] + values[i][j - 1] - values[i - 1][j - 1];
        }
    }

    auto query = [](std::vector<std::vector<int>>& pre, int rs, int cs, int re, int ce) -> int {
        return pre[re][ce] - pre[re][cs - 1] - pre[rs - 1][ce] + pre[rs - 1][cs - 1];
    };

    int max_cnt = 0;

    for (int rs = 1; rs <= h; rs++) {
        for (int re = rs; re <= h; re++) {
            // rs -> re, 贪心c
            int cs = 1, ce = 1;
            while (ce <= w) {
                int v = query(values, rs, cs, re, ce);
                while (v > S && ++cs <= ce) {
                    v = query(values, rs, cs, re, ce);
                }
                max_cnt = std::max(max_cnt, query(cnts, rs, cs, re, ce));
                ce++;
            }
        }
    }

    std::cout << max_cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}