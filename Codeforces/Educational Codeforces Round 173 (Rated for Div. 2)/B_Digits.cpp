#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

i64 fact(int x) {
    int ans = 1;
    for (int i = 2; i <= x; i++) {
        ans *= i;
    }
    return ans;
}

void solve() {
    int N, D;
    std::cin >> N >> D;
    std::vector<int> ans;
    ans.emplace_back(1);
    bool d3 = D == 3 || N >= 3 || fact(N) * D % 3 == 0;
    if (d3) ans.emplace_back(3);

    if (D == 5) ans.emplace_back(5);

    if (D == 7 || N >= 3) ans.emplace_back(7);
    
    if (D == 9 || N >= 6) ans.emplace_back(9);
    else if (N >= 3 && (D == 3 || D == 6)) ans.emplace_back(9);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}