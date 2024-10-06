#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector map(N + 1, std::vector<int>(N + 1, 0));
    std::vector diff(N + 2, std::vector<int>(N + 2, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] = map[i][j] - map[i - 1][j] - map[i][j - 1] + map[i - 1][j - 1];
        }
    }

#if 0
求和
+-
-+
#endif

    while (M--) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

#if 0
修改
###+@@@-
###@@@@#
###-###+
#endif

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = diff[i][j] + map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void solve1()
{
    int N, M;
    std::cin >> N >> M;
    std::vector map(N + 1, std::vector<int>(N + 1, 0));
    std::vector diff(N + 2, std::vector<int>(N + 2, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] = map[i][j] - map[i - 1][j] - map[i][j - 1] + map[i - 1][j - 1];
        }
    }


#if 0
求和
+-
-+
#endif

    while (M--) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

#if 0
修改
###+@@@-
###@@@@#
###-###+
#endif

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += diff[i - 1][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cout << diff[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void solve2()
{
    int N, M;
    std::cin >> N >> M;
    std::vector map(N + 1, std::vector<int>(N + 1, 0));
    std::vector diff(N + 2, std::vector<int>(N + 2, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
        }
    }

#if 0
求和
+-
-+
#endif

    while (M--) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

#if 0
修改
###+@@@-
###@@@@#
###-###+
#endif

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += map[i][j] + map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
            std::cout << diff[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void best()
{
    int N, M;
    std::cin >> N >> M;
    std::vector map(N + 1, std::vector<int>(N + 1, 0));
    std::vector diff(N + 2, std::vector<int>(N + 2, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
        }
    }

    while (M--) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

#if 0
修改
###+@@@-
###@@@@#
###-###+
#endif

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += diff[i - 1][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cout << diff[i][j] + map[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    best();
    return 0;
}