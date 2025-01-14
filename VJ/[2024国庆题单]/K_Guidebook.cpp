#include <bits/stdc++.h>

struct canteen {
    int id;
    std::string name;
    int score;

    bool operator<(const canteen& another) const {
        if (name == another.name) return score > another.score;
        return name < another.name;
    }
};

void solve()
{
    int n;
    std::cin >> n;
    std::vector<canteen> canteens(n);
    for (int i = 0; i < n; i++) {
        canteens[i].id = i + 1;
        std::cin >> canteens[i].name >> canteens[i].score;
    }
    std::sort(canteens.begin(), canteens.end());
    for (int i = 0; i < n; i++) {
        std::cout << canteens[i].id << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}