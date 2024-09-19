#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, m, q;
    std::cin >> n >> m >> q; // n 单元格数 m 老师数 q 查询数
    std::vector<int> teachers(m);
    for (int i = 0; i < m; i++) {
        std::cin >> teachers[i];
        teachers[i]--;
    }
    std::sort(teachers.begin(), teachers.end());
    
    while(q--) {
        int pos;
        std::cin >> pos; // 大卫位置
        pos--;
        if (pos < teachers[0]) {
            std::cout << teachers[0] << std::endl;
        } else if (teachers[1] < pos) {
            std::cout << n - 1 - teachers[1] << std::endl;
        } else {
            std::cout << (teachers[1] - teachers[0]) / 2 << std::endl;
        }
    }
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