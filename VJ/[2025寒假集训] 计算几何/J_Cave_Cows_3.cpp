#include <bits/stdc++.h>

using i64 = long long;
using d64 = double;
using d128 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct Point {
    int x, y;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
    }
    std::sort(points.begin(), points.end(), [](Point& a, Point& b) {
        return a.x + a.y < b.x + b.y;
    });
    int ans1 = abs(points.back().x - points.front().x) + abs(points.back().y - points.front().y);
    std::sort(points.begin(), points.end(), [](Point& a, Point& b) {
        return a.x - a.y < b.x - b.y;
    });
    int ans2 = abs(points.back().x - points.front().x) + abs(points.back().y - points.front().y);
    std::cout << std::max(ans1, ans2) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}