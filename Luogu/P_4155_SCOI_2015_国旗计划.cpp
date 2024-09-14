#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct soldier {
public:
    int id; // 士兵编号
    int l, r; // 驻守的左右边界
    bool operator<(const soldier other) const { return l < other.l; }
};

void solve()
{
    int N, M; // N: 人数, M: 边防站数量
    std::cin >> N >> M;
    std::vector<soldier> C(2 * N); // 0 -> 1 顺时针
    for (int i = 0; i < N; i++) {
        C[i].id = i + 1;
        std::cin >> C[i].l >> C[i].r;
        C[i].l--; C[i].r--;
        if (C[i].r < C[i].l) C[i].r += M;
    }
    std::sort(C.begin(), C.begin() + (C.size() >> 1)); // 按左边界单调增排序
    for (int i = 0; i < N; i++) { // 开环复制模拟成链
        C[N + i] = C[i];
        C[N + i].l += M;
        C[N + i].r += M;
    }
    std::cerr << '['; for (int i = 0; i < C.size(); i++) { std::cerr << '[' << C[i].l << '-' << C[i].r << ']'; if (i != C.size() - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;
    // 找每一个区间的下一个最优区间，然后倍增
    int index = 0, N2 = N * 2, temp = 0;
    while ((1 << temp) <= N) temp++;
    // DEBUG(temp);
    std::vector go(N2, std::vector<int>(temp));
    // go[s][i] 中s为(起点节点)，2^i为(跳的步数)

    for (int i = 0; i < N2; i++) {
        while (index < N2 && C[index].l < C[i].r) index++;
        go[i][0] = index - 1;
        DEBUG("go[" << i << ',' << 0 << "]: " << go[i][0]);
    }

    for (int i = 1; i < temp; i++) {
        for (int s = 0; s < N2; s++) {
            go[s][i] = go[go[s][i - 1]][i - 1];
            DEBUG("go[" << s << ',' << i << "]: " << go[s][i]);
        }
    }
    
    auto getAns = [&](int x) -> int {
        DEBUG("get x: " << x)
        int len = C[x].l + M, cur = x, ans = 1;
        for (int i = temp - 1; i >= 0; i--) {
            int pos = go[cur][i];
            if (C[pos].r < len) {
                ans += 1 << i;
                DEBUG("jumped: " << (1 << i) << ", toPos:" << pos << "| L:" << C[pos].l << " R:" << C[pos].r << " len:" << len)
                cur = pos;
            }
        }
        return ans + 1;
    };

    for (int i = 0; i < N; i++) std::cout << getAns(i) << ' ';
    std::cout << std::endl;
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