#include <bits/stdc++.h>

void solve()
{
    //LOG("=====")
    int N, K;
    std::cin >> N >> K;
    std::vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cards[i];
    }
    std::sort(cards.begin(), cards.end());
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    int L = 0, R = 0;
    int Ln = -1, Rn = -1;
    int max = -1;
    while (r2 < N) {
        l2 = r2;
        while (r2 < N && cards[r2] == cards[l2]) {
            r2++;
        }
        R++;
        if (Rn != -1 && cards[l2] - Rn > 1) {
            L = R;
            l1 = l2;
            r1 = r2;
        }
        Rn = cards[l2];
        while (R - L >= K) {
            l1 = r1;
            while (cards[r1] == cards[l1]) {
                r1++;
            }
            L++;
        }
        Ln = cards[l1];
        //LOG(l1 << ',' << r1 << " | " << l2 << ',' << r2 << " | ln: " << Ln << " Rn:" << Rn << " | v = " << r2 - l1)
        max = std::max(max, r2 - l1);
    }
    std::cout << max << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}