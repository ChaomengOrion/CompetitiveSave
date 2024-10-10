#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                       \
    std::cerr << #_vec << " = " << '[';         \
    for (int _i = 0; _i < _size; _i++) {        \
        std::cerr << _vec[_i];                  \
        if (_i != _size - 1) std::cerr << ", "; \
    }                                           \
    std::cerr << ']' << std::endl;
bool vis[100];
int pieces[100];
int rest[100];
int targetRod, targetLen, N;

void solve()
{
    std::cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> pieces[i];
        sum += pieces[i];
    }
    std::sort(pieces, pieces + N + 1, std::greater<int>());

    int temp = 0;
    for (int i = 0; i < N; i++) {
        rest[i] = sum - temp;
        temp += pieces[i];
    }

    // std::array<bool, 100> vis;
    // int CNT = 0;
    auto dfs = [&](auto&& dfs, const int rod, const int s, const int curLen) -> bool {
        if (rod >= targetRod) return 1;
        if (curLen == targetLen) return dfs(dfs, rod + 1, 0, 0);
        int last = -1, restLen = targetLen - curLen;
        int l = s, r = N - 1, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(pieces[mid]<=restLen) r = mid;
            else l = mid + 1;
        }
        for (int i = l; i < N; i++) {
            if (rest[i] < targetLen - curLen) break;
            if (vis[i] || pieces[i] + curLen > targetLen || pieces[i] == last) continue;
            last = pieces[i];
            vis[i] = 1;
            if (dfs(dfs, rod, i + 1, curLen + pieces[i])) return 1;
            vis[i] = 0;
            if (curLen == 0 || curLen + pieces[i] == targetLen) return 0;
        }
        return 0;
    };
    // LOGV(pieces, N)
    int max = pieces[0], ans = sum;
    for (int len = max; len < sum; len++) {
        if (sum % len != 0) continue; // 剪枝掉非因数
        targetLen = len;
        targetRod = sum / len;
        memset(vis, 0, sizeof(vis));
        if (dfs(dfs, 0, 0, 0)) {
            ans = len;
            break;
        }
    }

    std::cout << ans << std::endl;
    // std::cout << CNT << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}