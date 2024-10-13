#include <bits/stdc++.h>

struct people {
    std::string name;
    int birth;
    int id;

    bool operator<(const people& another) const
    {
        if (birth == another.birth) return id > another.id;
        return birth < another.birth;
    }
};

void solve()
{
    int N;
    std::cin >> N;
    std::vector<people> peoples(N);
    for (int i = 0; i < N; i++) {
        int y, m, d;
        std::cin >> peoples[i].name >> y >> m >> d;
        y -= 1960;
        m--;
        d--;
        peoples[i].birth = y * (12 * 31) + m * 31 + d;
        peoples[i].id = i;
    }
    // std::sort(ps.begin(), ps.end());
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (peoples[j] < peoples[j + 1]) continue;
            //std::swap(peoples[j], peoples[j + 1]);
            people temp = peoples[j];
            peoples[j] = peoples[j + 1];
            peoples[j + 1] = temp;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << peoples[i].name << std::endl;
    }
}

int main()
{
    //std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}