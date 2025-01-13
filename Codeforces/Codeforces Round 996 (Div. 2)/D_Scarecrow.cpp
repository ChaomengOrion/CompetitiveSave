#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 N, K, L;
    std::cin >> N >> K >> L;
    std::vector<i64> pos2(N);
    for (int i = 0; i < N; i++) {
        std::cin >> pos2[i];
        pos2[i] *= 2;
    }
    std::sort(pos2.begin(), pos2.end());

    i64 birdPos2 = 0;
    int lastCrow = -1;
    i64 time2 = 0; //! 记得x2
    std::vector<i64> time2_uesd(N);

    auto tryMove = [&](int crowId, int targetPos2) -> void {
        i64 d2 = targetPos2 - pos2[crowId];
        i64 tu2 = std::min(time2 - time2_uesd[crowId], abs(d2));
        time2_uesd[crowId] += tu2;
        pos2[crowId] = d2 > 0 ? pos2[crowId] + time2_uesd[crowId] : pos2[crowId] - time2_uesd[crowId];
    };

    auto jump = [&]() -> void {
        assert(lastCrow != -1);
        assert(pos2[lastCrow] <= birdPos2 && birdPos2 - pos2[lastCrow] < K * 2);
        birdPos2 = pos2[lastCrow] + K * 2;
        for (int i = lastCrow + 1; i < N; i++) {
            tryMove(i, birdPos2);
            if (birdPos2 >= pos2[i]) {
                lastCrow = i;
                birdPos2 = pos2[i] + K * 2;
            } else break;
        }
    };

    {
        lastCrow = 0;
        i64 dis2 = pos2[lastCrow] - birdPos2;
        pos2[lastCrow] = birdPos2;
        time2 += dis2;
        time2_uesd[lastCrow] = dis2;
        jump();
    }

    while (birdPos2 < L * 2) {
        assert(pos2[lastCrow] <= birdPos2);
        if (lastCrow == N - 1) {
            time2 += L * 2 - birdPos2;
            birdPos2 = 2 * L;
            break;
        }

        lastCrow++;
        i64 dis2 = pos2[lastCrow] - birdPos2;
        dis2 /= 2;
        pos2[lastCrow] = birdPos2 = birdPos2 + dis2;
        time2 += dis2;
        time2_uesd[lastCrow] = dis2;
        jump();
    }

    std::cout << time2 << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}