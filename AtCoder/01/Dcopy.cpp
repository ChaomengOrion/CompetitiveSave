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

    std::vector map(H, std::vector<bool>(W, true));

    int cnt = 0;
    while (Q--) {
        int i, j;
        std::cin >> i >> j;
        i--; j--;
        if (map[i][j]) {
            map[i][j] = false;
            cnt++;
            //DEBUGI(i+1, j+1);
        }
        else {
            int ri = i, rj = j;
            while (++ri < H) {
                if (map[ri][rj]) {
                    map[ri][rj] = false;
                    //DEBUGI(ri+1, rj+1);
                    cnt++;
                    break;
                }
            }
            ri = i, rj = j;
            while (--ri >= 0) {
                if (map[ri][rj]) {
                    map[ri][rj] = false;
                    //DEBUGI(ri+1, rj+1);
                    cnt++;
                    break;
                }
            }
            ri = i, rj = j;
            while (++rj < W) {
                if (map[ri][rj]) {
                    map[ri][rj] = false;
                    //DEBUGI(ri+1, rj+1);
                    cnt++;
                    break;
                }
            }
            ri = i, rj = j;
            while (--rj >= 0) {
                if (map[ri][rj]) {
                    map[ri][rj] = false;
                    //DEBUGI(ri+1, rj+1);
                    cnt++;
                    break;
                }
            }
        }
    }

    std::cout << H * W - cnt << std::endl;
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