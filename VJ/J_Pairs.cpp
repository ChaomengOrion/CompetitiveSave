#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int N; i64 K;
    std::cin >> N >> K;
    std::vector<i64> arr(N);
    for (int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr.begin(), arr.end());
    i64 L = -1e18, R = 1e18;
    while (L < R) {
        i64 Mid = L + (R - L) / 2;
        i64 cnt = 0; // 比k小的数量
        for (int i = 0; i < N; i++) {
            if (arr[i] < 0) { // 往上找
                int l = i + 1, r = N;
                while (r - l > 0) {
                    int mid = (l + r) >> 1;
                    if (arr[i] * arr[mid] <= Mid) r = mid;
                    else l = mid + 1;
                }
                cnt += N - l;
            } else { // 往下找
                int l = i, r = N - 1;
                while (r - l > 0) {
                    int mid = (l + r + 1) >> 1;
                    if (arr[i] * arr[mid] <= Mid) l = mid;
                    else r = mid - 1;
                }
                cnt += l - i;
            }
        }
        if (cnt < K) L = Mid + 1;
        else R = Mid;
    }
    std::cout << R << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}