#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#    include "[debug]util.hpp"
#    define LOG(...) \
        std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#    define LOGI(info, ...)                                        \
        std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#    define LOGA(...)                           \
        std::cerr << "[" << __LINE__ << "]: [", \
            __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#    define LOG(...)
#    define LOGI(...)
#    define LOGA(...)
#endif

using i64 = long long;

void solve() {
    i64 N, K;
    std::cin >> N >> K;
    std::vector<i64> arr(N);
    std::map<i64, std::vector<i64>, std::greater<>> n2pos;
    for (i64 i = 0; i < N; i++) {
        std::cin >> arr[i];
        n2pos[arr[i]].emplace_back(i);
    }
    std::set<i64> cut;

    auto check = [&](i64 l, i64 r) -> bool {
        auto it = cut.upper_bound(l);
        if (it == cut.end()) {
            LOG(l, r, "end");
            return true;
        }

        LOG(l, r, *it, r);
        return *it > r;
    };

    auto cal = [&](i64 n, i64 k) -> i64 {
        i64 sum = 0;
        for (i64 l = k; l <= n; l++) {
            sum += n + 1 - l;
        }
        LOG("cal", n, k, sum);
        return sum;
    };

    i64 ans = 0;

    auto add = [&](i64 l, i64 r, i64& cnt, std::vector<i64>& gap) {
        i64 lcnt = 0, rcnt = 0;
        auto lt = cut.lower_bound(l);
        if (lt != cut.begin()) {
            lcnt = l - (*std::prev(lt) + 1);
        } else {
            lcnt = l;
        }
        auto rt = cut.upper_bound(r);
        if (rt != cut.end()) {
            rcnt = (*rt - 1) - r;
        } else {
            rcnt = N - 1 - r;
        }
        i64 mid = cal(r - l + 1, 1);

        for (i64 i = 0; i < gap.size(); i++) {
            mid -= cal(gap[i], 1);
        }
        gap.clear();
        mid -= cal(K, 1);
        cnt = 0;

        ans += mid * (lcnt + 1) * (rcnt + 1);
        LOG(l, r, lcnt, rcnt, ans);
    };

    for (auto&& pair : n2pos) {
        auto [n, pos] = std::forward_as_tuple(pair.first, pair.second);
        LOG(n);
        i64 l = -1, r = -1;
        i64 cnt = 0;
        std::vector<i64> gap;
        for (i64 i = 0; i < pos.size(); i++) {
            cnt++;
            if (i > 0 && pos[i] > pos[i - 1] + 1) {
                gap.emplace_back(pos[i] - 1 - pos[i - 1]);
            }
            if (l == -1) {
                l = r = pos[i];
            } else if (!check(r, pos[i])) {
                add(l, r, cnt, gap);
                l = r = pos[i];
            } else {
                r = pos[i];
            }
            LOG(l, r);
        }
        add(l, r, cnt, gap);
        for (i64 i = 0; i < pos.size(); i++) {
            cut.emplace(pos[i]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}