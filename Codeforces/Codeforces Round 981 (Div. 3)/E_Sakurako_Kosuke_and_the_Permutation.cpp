#include <bits/stdc++.h>

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> seq(N + 1);
    std::vector<int> index(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
        index[seq[i]] = i;
    }
    int opCnt = 0;
    std::vector<char> vis(N + 1);
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        if (seq[i] == i) {
            continue;
        }
        if (seq[seq[i]] == i) {
            vis[seq[i]] = true;
            continue;
        } else {
            int targetPos = index[i];
            std::swap(index[i], index[seq[seq[i]]]);
            std::swap(seq[targetPos], seq[seq[i]]);
            vis[seq[i]] = true;
            opCnt++;
        }
    }
    std::cout << opCnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}