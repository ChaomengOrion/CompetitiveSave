#include <bits/stdc++.h>

struct point {
    int x,y;
};

void solve()
{
    int N;
    std::cin >> N;
    std::vector<point> points(N);

    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                double x1 = points[i].x, y1 = points[i].y,
                    x2 = points[j].x, y2 = points[j].y,
                    x3 = points[k].x, y3 = points[k].y;
                if ((y1 - y3) * (x2 - x3) == (y2 - y3) * (x1 - x3)) {
                    std::cout << "Yes" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "No" << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}