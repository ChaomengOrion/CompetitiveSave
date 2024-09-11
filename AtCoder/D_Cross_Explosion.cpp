#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    int H, W, Q;
    std::cin >> H >> W >> Q;

    std::set<int> w;
    std::set<int> h;

    for (int i = 0; i < W; i++) {
        w.insert(i);
    }
    for (int i = 0; i < H; i++) {
        h.insert(i);
    }

    std::vector mapFromTop(W, h);
    std::vector mapFromLeft(H, w);

    auto erase = [&](int i, int j) { mapFromLeft[i].erase(j), mapFromTop[j].erase(i); };

    while (Q--) {
        int i, j;
        std::cin >> i >> j;
        i--; j--;

        // -> Right

        if (mapFromLeft[i].contains(j)) {
            erase(i, j);
            continue;
        }

        auto it = mapFromLeft[i].lower_bound(j);
        if (it != mapFromLeft[i].end()) {
            erase(i, *it);
        }

        // <- Left
        it = mapFromLeft[i].lower_bound(j);
        if (it != mapFromLeft[i].begin()) {
            erase(i, *--it);
        }

        // Down
        it = mapFromTop[j].lower_bound(i);
        if (it != mapFromTop[j].end()) {
            erase(*it, j);
        }

        // Up
        it = mapFromTop[j].lower_bound(i);
        if (it != mapFromTop[j].begin()) {
            erase(*--it, j);
        }
    }

    int sum = 0;
    for (int i = 0; i < H; i++) {
        sum += mapFromLeft[i].size();
    }
    std::cout << sum << std::endl;
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
} // 拆数字