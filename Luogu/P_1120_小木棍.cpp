#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < _size; _i++) { std::cerr << _vec[_i]; if (_i != _size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> pieces(N);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> pieces[i];
        sum += pieces[i];
    }
    std::sort(pieces.begin(), pieces.end(), std::greater<int>());

    std::vector<bool> vis(N, false);
    int CNT = 0;
    auto dfs = [&](auto&& dfs, int start, int cur, int target) -> bool {
        //LOGV(vis, N)
        int last = -1;
        for (int i = start; i < N; i++) {
            if (vis[i] || (i > 0 && pieces[i] == last)) continue;
            last = pieces[i];
            if (cur + pieces[i] < target) {
                vis[i] = true;
                if (dfs(dfs, start + 1, cur + pieces[i], target)) {
                    return true;
                }
                vis[i] = false;
            } else if (cur + pieces[i] == target) {
                vis[i] = true;
                CNT--;
                if (CNT == 0 || dfs(dfs, 0, 0, target)) { // 重头找下一个
                    return true;
                }
                vis[i] = false;
                CNT++;
                //return true;
            }
        }
        return false;
    };
    //LOGV(pieces, N)
    int min = sum;
    for (int len = 1; len < sum; len++) {
        if (sum % len != 0) continue; // 剪枝掉非因数
        int L = sum / len;
        bool ok = true;
        std::fill(vis.begin(), vis.end(), false);
        CNT = L;
        //LOG(len << " = " << ok)
        if (dfs(dfs, 0, 0, len)) {
            min = std::min(min, len);
            break;
        }
    }

    std::cout << min << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}