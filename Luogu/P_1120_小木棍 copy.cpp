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
int targetRod, targetLen;
int N;

bool dfs1(const int rod, const int s, const int curLen)
{
    if (rod >= targetRod) return 1;
    if (curLen == targetLen) return dfs1(rod + 1, 0, 0);
    int last = -1;
    for (int i = s; i < N; i++) {
        if (rest[i] < targetLen - curLen) break;
        if (vis[i] || pieces[i] + curLen > targetLen || pieces[i] == last) continue;
        last = pieces[i];
        vis[i] = 1;
        if (dfs1(rod, i + 1, curLen + pieces[i])) return 1;
        vis[i] = 0;
        if (curLen == 0 || curLen + pieces[i] == targetLen) return 0;
    }
    return 0;
}

bool dfs2(const int rod, const int s, const int curLen)
{
    if (rod >= targetRod) return 1;
    if (curLen == targetLen) return dfs2(rod + 1, 0, 0);
    int last = -1;
    for (int i = s; i < N; i++) {
        if (rest[i] < targetLen - curLen) break;
        if (!vis[i] && curLen + pieces[i] <= targetLen && last != pieces[i]) {
            vis[i] = 1;
            if (dfs2(rod, i + 1, curLen + pieces[i])) return 1;
            last = pieces[i];
            vis[i] = 0;
            if (curLen == 0 || curLen + pieces[i] == targetLen) return 0;
        }
    }
    return 0;
}

void solve();
/*{
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
    // LOGV(pieces, N)
    int max = pieces[0], ans = sum;
    for (int len = max; len < sum; len++) {
        if (sum % len != 0) continue; // 剪枝掉非因数
        targetLen = len;
        targetRod = sum / len;
        memset(vis, 0, sizeof(vis));
        // std::fill(vis.begin(), vis.end(), false);
        // LOG("=========== try len = " << len)
        if (dfs(0, 0, 0)) {
            ans = len;
            break;
        }
    }

    std::cout << ans << std::endl;
    // std::cout << CNT << std::endl;
}*/

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}

using namespace std;
void solve()
{
    cin >> N;
    //memset(pieces, 0, sizeof(pieces));
    int sum = 0, l;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pieces[i] = x;
        sum += x;
    }
    sort(pieces, pieces + N + 1, greater<int>());
    int temp = 0;
    for (int i = 0; i < N; i++) {
        rest[i] = sum - temp;
        temp += pieces[i];
    }
    for (l = pieces[0]; l <= sum; l++) {
        if (sum % l != 0) continue;
        targetRod = sum / l;
        targetLen = l;
        memset(vis, 0, sizeof(vis));
        if (dfs1(0, 0, 0)) break;
    }
    cout << l << endl;
}