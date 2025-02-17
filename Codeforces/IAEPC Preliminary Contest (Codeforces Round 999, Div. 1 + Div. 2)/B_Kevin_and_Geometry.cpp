#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    int eq = -1; int pa = -1, pb = -1;
    for (int i = N - 1; i >= 1; i--) {
        if (arr[i] == arr[i - 1]) {
            eq = arr[i];
            pa = i; pb = i - 1;
            break;
        }
    }
    if (eq == -1) {
        std::cout << -1 << '\n';
        return;
    }
    int last = -1;
    for (int i = 0; i < N; i++) {
        if (i == pa || i == pb) continue;
        if (last == -1) last = arr[i];
        else {
            int delta = arr[i] - last;
            if (delta < 2 * eq) {
                std::cout << eq << ' ' << eq << ' ' << last << ' '<< arr[i] << '\n';
                return;
            }
            last = arr[i];
        }
    }
    std::cout << -1 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}