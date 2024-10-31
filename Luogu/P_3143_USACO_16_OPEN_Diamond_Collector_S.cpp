#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    std::vector<int> toRight(N), toLeft(N);
    int l = 0, r = 0;
    for (; l < N; l++) {
        int cur = arr[l];
        while (r < N && arr[r] - cur <= K) r++;
        toRight[l] = r - l;
    }
    l = N - 1, r = N - 1;
    for (; r >= 0; r--) {
        int cur = arr[r];
        while (l >= 0 && cur - arr[l] <= K) l--;
        toLeft[r] = r - l;
    }
    int max = std::max(toRight[0], toLeft[N - 1]);
    int lmax = 0;
    for (int i = 1; i < N; i++) {
        lmax = std::max(lmax, toLeft[i - 1]);
        max = std::max(max, lmax + toRight[i]);
    }
    std::cout << max << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}