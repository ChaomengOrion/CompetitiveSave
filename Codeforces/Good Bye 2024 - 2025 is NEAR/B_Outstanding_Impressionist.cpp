#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N; //2E5
    std::cin >> N;
    std::vector<std::pair<int, int>> ranges(N);
    std::map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        std::cin >> ranges[i].first >> ranges[i].second;
        if (ranges[i].first == ranges[i].second) {
            cnt[ranges[i].first]++;
        }
    }
    std::map<int, int> cnt2;
    int cot = 0;
    for (auto [k, v] : cnt) {
        cnt2[k] = cot++;
    }
    for (int i = 0; i < N; i++) {
        if (ranges[i].first == ranges[i].second) {
            if (cnt[ranges[i].first] >= 2) {
                std::cout << '0';
            } else {
                std::cout << '1';
            }
        } else {
            auto l = cnt.find(ranges[i].first);
            auto r = cnt.find(ranges[i].second);
            if (l == cnt.end() || r == cnt.end() || (cnt2[ranges[i].second] - cnt2[ranges[i].first]) < ranges[i].second - ranges[i].first) {
                std::cout << '1';
            }
            else std::cout << '0';
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}