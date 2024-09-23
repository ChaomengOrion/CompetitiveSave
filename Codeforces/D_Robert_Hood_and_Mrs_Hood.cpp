#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, d, k;
    std::cin >> n >> d >> k;
    std::vector<std::pair<int, int>> works(k);
    for (int i = 0; i < k; i++) {
        std::cin >> works[i].first >> works[i].second;
    }
    std::vector<int> starts(n + 1, 0), ends(n + 1, 0);
    for (auto [start, end] : works) {
        starts[start] += 1;
        ends[end] += 1;
    }

    // 处理前缀和
    for (int i = 1; i <= n; i++) {
        starts[i] += starts[i - 1];
        ends[i] += ends[i - 1];
    }

    auto calWorks = [&] (int start, int end) -> int { // 计算天数内覆盖的works数量，闭区间
        return starts[end] - ends[start - 1];
    };

    int min_cnt = INT_MAX, min_day_start = -1,
        max_cnt = -1, max_day_start = -1;
    
    d--;
    for (int i = 1; i <= n - d; i++) {
        int cnt = calWorks(i, i + d);
        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_day_start = i;
        }
        if (cnt < min_cnt) {
            min_cnt = cnt;
            min_day_start = i;
        }
    }

    std::cout << max_day_start << ' ' << min_day_start << std::endl;
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