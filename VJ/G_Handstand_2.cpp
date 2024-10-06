#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int d[11][11] = {};

    for (int i = 1; i <= n; i++) {
        d[std::to_string(i)[0] - '0'][i % 10]++;
    }

    int res = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            res += d[i][j] * d[j][i];

    std::cout << res << std::endl;
    return 0;
}