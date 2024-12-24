#include <bits/stdc++.h>

using i64 = long long;

struct event {
    int val; //* 2e9
    char type;

    bool operator<(const event& other) const {
        return val < other.val;
    }
};

void solve() {
    int N, K; //* 2e5
    std::cin >> N >> K;
    std::vector<event> events(2 * N);
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        events[i] = { temp, 1 };
    }
    for (int i = N; i < 2 * N; i++) {
        int temp;
        std::cin >> temp;
        events[i] = { temp, -1 };
    }
    std::sort(events.begin(), events.end());

    int badCnt = 0, goodCnt = N;
    i64 maxSold = 0;

    int lastPrice = -1;
    int badTemp = 0, goodTemp = 0;

    for (int i = 0; i < 2 * N; i++) {
        event cur = events[i];
        if (lastPrice != cur.val) {
            lastPrice = cur.val;
            badCnt += badTemp;
            goodCnt += goodTemp;
            badTemp = goodTemp = 0;
            if (badCnt <= K) {
                maxSold = std::max(maxSold, 1LL * lastPrice * (goodCnt + badCnt));
            }
        }

        if (cur.type == 1) {
            goodTemp--;
            badTemp++;
        } else {
            badTemp--;
        }
    }

    std::cout << maxSold << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}