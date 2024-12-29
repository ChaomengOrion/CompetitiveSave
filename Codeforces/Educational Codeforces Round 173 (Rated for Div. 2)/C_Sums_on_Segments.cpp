#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;

void solve() {
    i64 N;
    std::cin >> N;
    std::vector<i64> arr(N);
    i64 diff = -1;
    for (i64 i = 0; i < N; i++) {
        std::cin >> arr[i];
        if (arr[i] != 1 && arr[i] != -1) diff = i;
    }
    auto count = [&](i64 L, i64 R) -> std::pair<i64, i64> {
        i64 l = 0, r = 0;
        std::pair<i64, i64> ans = {0, 0};
        i64 sum = 0;
        for (i64 i = L; i <= R; i++) {
            sum += arr[i];
            ans.first = std::min(ans.first, sum - r);
            ans.second = std::max(ans.second, sum - l);
            l = std::min(l, sum);
            r = std::max(r, sum);
        }
        return ans;
    };
    auto toRight = [&](i64 L, i64 R) -> std::pair<i64, i64> {
        std::pair<i64, i64> ans = {0, 0};
        i64 sum = 0;
        for (i64 i = L; i <= R; i++) {
            sum += arr[i];
            ans.first = std::min(ans.first, sum);
            ans.second = std::max(ans.second, sum);
        }
        return ans;
    };
    auto toLeft = [&](i64 L, i64 R) -> std::pair<i64, i64> {
        std::pair<i64, i64> ans = {0, 0};
        i64 sum = 0;
        for (i64 i = R; i >= L; i--) {
            sum += arr[i];
            ans.first = std::min(ans.first, sum);
            ans.second = std::max(ans.second, sum);
        }
        return ans;
    };
    if (diff == -1) {
        auto [l, r] = count(0, N - 1);
        std::cout << r - l + 1 << std::endl;
        for (i64 i = l; i <= r; i++) {
            std::cout << i << ' ';
        }
    } else { // TODO
        auto Lcnt = count(0, diff - 1);
        auto Rcnt = count(diff + 1, N - 1);

        auto LRange = toLeft(0, diff - 1);
        auto RRange = toRight(diff + 1, N - 1);
        i64 mid = arr[diff];
        std::pair<i64, i64> newRange = {LRange.first + RRange.first + mid,
                                        LRange.second + RRange.second + mid};

        std::set<i64> ans;
        for (i64 i = Lcnt.first; i <= Lcnt.second; i++) {
            ans.emplace(i);
        }
        for (i64 i = Rcnt.first; i <= Rcnt.second; i++) {
            ans.emplace(i);
        }
        for (i64 i = newRange.first; i <= newRange.second; i++) {
            ans.emplace(i);
        }
        std::cout << ans.size() << std::endl;
        for (i64 i : ans) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}