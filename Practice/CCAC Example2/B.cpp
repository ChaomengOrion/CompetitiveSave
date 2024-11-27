#include <bits/stdc++.h>

const char layer[4] = {'s', 'p', 'd', 'f'};
const int count[4] = {2, 6, 10, 14};

void solve() {
    int N;
    std::cin >> N;
    
    int p = 0;
    int x = 0, y = 0;
    
    int cnt = 0;
    auto moveNext = [&]() -> void {
        x += 1; y -= 1;
        if (y < 0) {
            p++;
            x = (p + 1) / 2;
            y = p / 2;
        }
        cnt = 0;
    };

    std::vector<std::vector<std::string>> ans;

    while (N--) {
        cnt++;
        if (cnt == count[y]) {
            if (ans.size() < x + 1) {
                ans.push_back(std::vector<std::string> {layer[y] + std::to_string(count[y])});
            }
            else {
                ans[x].push_back(layer[y] + std::to_string(count[y]));
            }
            moveNext();
        }
    }
    if (cnt > 0) {
        if ((int)ans.size() < x + 1) {
            ans.push_back(std::vector<std::string> {layer[y] + std::to_string(cnt)});
        }
        else {
            ans[x].push_back(layer[y] + std::to_string(cnt));
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 0; j < (int)ans[i].size(); j++) {
            std::cout << i + 1 << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    solve();
}