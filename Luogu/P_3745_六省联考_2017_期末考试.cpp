#include <bits/stdc++.h>

using i64 = long long;

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
            return pt * A + (rt - pt) * B;
        } else {
            for (int i = 0; i < m; i++) {
                if (b[i] > time) rt += b[i] - time;
            }
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
        return sum;
    };

    int l = 1, r = b.back();
    while (r - l > 2) {
        int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        i64 c1 = calMove(mid1) + calWait(mid1);
        i64 c2 = calMove(mid2) + calWait(mid2);
        if (c2 > c1) r = mid2;
        else l = mid1;
    }
    i64 ans = LONG_LONG_MAX;
    for (int i = l; i <= r; i++) {
        ans = std::min(ans, calMove(i) + calWait(i));
    }
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}