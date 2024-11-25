#include <bits/stdc++.h>

struct Point {
    bool isAdd;
    int start;
    int val;

    bool operator<(const Point& other) const {
        if (start == other.start) return val > other.val;
        return start < other.start;
    }
};

void solve() {
    int N, M, L;
    std::cin >> N >> M >> L;
    std::vector<Point> points(N + M);
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        points[i] = {false, l, r - l};
    }
    for (int i = N; i < N + M; i++) {
        int s, v;
        std::cin >> s >> v;
        points[i] = {true, s, v};
    }
    std::sort(points.begin(), points.end());
    std::priority_queue<int> adds;
    int opCnt = 0, used = 1;
    for (int i = 0; i < N + M; i++) {
        if (points[i].isAdd) {
            adds.push(points[i].val);
        } else {
            int need = points[i].val + 2;
            while (used < need) {
                if (adds.empty()) {
                    std::cout << -1 << std::endl;
                    return;
                }
                opCnt++;
                used += adds.top();
                adds.pop();
            }
        }
    }
    std::cout << opCnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}