#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    i64 A, B, C, n, m;
    std::cin >> A >> B >> C >> n >> m;
    std::vector<int> t(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::sort(b.begin(), b.end());

    auto calMove = [&](int time) -> i64 {
        i64 lt = 0, rt = 0;
        if (A < B) {
            for (int i = 0; i < m; i++) {
                if (b[i] < time) lt += time - b[i];
                else rt += b[i] - time;
            }
            i64 pt = std::min(lt, rt);
            DEBUG("calMove: " << pt * A + (rt - pt) * B);
            return pt * A + (rt - pt) * B;
        } else {
            for (int i = 0; i < m; i++) {
                if (b[i] > time) rt += b[i] - time;
            }
            DEBUG("calMove: " << rt * B);
            return rt * B;
        }
    };

    if (C >= 1E16) {
        std::cout << calMove(*std::min_element(t.begin(), t.end())) << std::endl;
        return;
    }

    auto calWait = [&](int time) -> i64 {
        i64 sum = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] < time) sum += 1LL * (time - t[i]) * C;
        }
        DEBUG("calWait: " << sum);
        return sum;
    };

    int l = 1, r = b.back();
    while (r - l > 2) {
        int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        DEBUG(l << '|' << r)
        DEBUG("cal: " << mid1);
        i64 c1 = calMove(mid1) + calWait(mid1);
        DEBUG("cal: " << mid2);
        i64 c2 = calMove(mid2) + calWait(mid2);
        if (c2 > c1) r = mid2;
        else l = mid1;
    }
    DEBUG(l << '-' << r)
    i64 ans = LONG_LONG_MAX;
    for (int i = l; i <= r; i++) {
        DEBUG("cal: " << i);
        ans = std::min(ans, calMove(i) + calWait(i));
    }
    std::cout << ans << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}