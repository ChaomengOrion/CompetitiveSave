#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;


struct Building {
    i64 t1;
    i64 t2;
};

bool cmp(Building a, Building b) {
    return a.t2 < b.t2;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<Building> builds(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> builds[i].t1 >> builds[i].t2;
    }
    i64 sum = 0, ans = 0;
    std::priority_queue<i64> Q;
    std::sort(builds.begin() + 1, builds.end(), cmp);
    for (int i = 1; i <= n; i++) {
        sum += builds[i].t1;
        Q.push(builds[i].t1);
        if (sum <= builds[i].t2) {
            ans++;
        } else {
            sum -= Q.top();
            Q.pop();
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}