#include <bits/stdc++.h>

struct attck {
    int la, ra, lb, rb, lc, rc, h;
};

void solve()
{
    int A, B, C, M;
    std::cin >> A >> B >> C >> M;
    std::vector hp(A + 1, std::vector(B + 1, std::vector<int>(C + 1)));
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++) std::cin >> hp[i][j][k];

    std::vector<attck> attcks(M);
    for (int i = 0; i < M; i++) {
        attck& at = attcks[i];
        std::cin >> at.la >> at.ra >> at.lb >> at.rb >> at.lc >> at.rc >> at.h;
    }

    auto check = [&](int x) -> bool {
        std::vector diff(A + 2, std::vector(B + 2, std::vector<int>(C + 2, 0)));

        for (int i = 0; i < x; i++) {
            attck& at = attcks[i];
            diff[at.la][at.lb][at.lc] += at.h;
            diff[at.ra + 1][at.lb][at.lc] -= at.h;
            diff[at.la][at.rb + 1][at.lc] -= at.h;
            diff[at.la][at.lb][at.rc + 1] -= at.h;
            diff[at.ra + 1][at.rb + 1][at.lc] += at.h;
            diff[at.ra + 1][at.lb][at.rc + 1] += at.h;
            diff[at.la][at.rb + 1][at.rc + 1] += at.h;
            diff[at.ra + 1][at.rb + 1][at.rc + 1] -= at.h;
        }

        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) diff[i][j][k] += diff[i - 1][j][k];

        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) diff[i][j][k] += diff[i][j - 1][k];

        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) diff[i][j][k] += diff[i][j][k - 1];

        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++)
                    if (diff[i][j][k] > hp[i][j][k]) return true;

        return false;
    };

    int l = 1, r = M;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) { // 炸了
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
}

int main()
{
    return std::cin.tie(nullptr)->sync_with_stdio(false), solve(), 0;
}