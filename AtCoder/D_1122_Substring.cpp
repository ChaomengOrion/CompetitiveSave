#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    int ans = 0;
    int l = -1;
    std::map<int, int> set;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            if (i - 1 >= 0 && S[i - 1] == S[i] && i + 2 < N && S[i + 1] == S[i + 2]) continue;
            l = -1;
            if (!set.empty()) set.clear();
        } else if (!set.contains(S[i]) || set[S[i]] < l) {
            if (l == -1) l = i;
            set[S[i]] = i;
            ans = std::max(ans, i + 2 - l);
        } else if (i - 2 >= 0 && S[i - 1] == S[i - 2] && S[i - 1] != S[i]) {
            l = set[S[i]] + 2;
            set[S[i]] = i;
            ans = std::max(ans, i + 2 - l);
        } else {
            set.clear();
            set.emplace(S[i], i);
            l = i;
            ans = std::max(ans, 2);
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}