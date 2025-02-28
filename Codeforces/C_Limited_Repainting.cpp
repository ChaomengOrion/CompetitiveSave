#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

struct node {
    int val;
    char type;
    int pos;
    bool operator<(const node& other) const {
        if (val == other.val) {
            return type == 'R' && other.type == 'B';
        }
        return val < other.val;
    }
};

void solve() {
    int N, K;
    std::string S;
    std::cin >> N >> K >> S;
    i64 sum = 0;
    std::priority_queue<node> Q;
    for (int i = 0; i < N; i++) {
        node temp;
        std::cin >> temp.val;
        temp.type = S[i];
        temp.pos = i;
        Q.emplace(temp);
    }
    auto cmp = [](const std::pair<int, int> a, const std::pair<int, int> b) {
        return a.second < b.first;
    };
    std::set<std::pair<int, int>, decltype(cmp)> rangesY(cmp);
    std::set<std::pair<int, int>, decltype(cmp)> rangesN(cmp);
    while (!Q.empty()) {
        std::vector<std::pair<int, int>> pos_val;
        node x = Q.top();
        LOG("Round", x.type);
        Q.pop();
        pos_val.emplace_back(x.pos, x.val);
        while (!Q.empty() && Q.top().type == x.type) {
            pos_val.emplace_back(Q.top().pos, Q.top().val);
            Q.pop();
        }

        int lastL = -1, lastR = -1, lastVal = -1;
        for (auto [p, val] : pos_val) {
            if (x.type == 'R') {
                LOG("rangesN", p, rangesY.contains({p, p}));
                if (rangesY.contains({p, p}) && !rangesN.contains({p - 1, p + 1})) {
                    auto [l, r] = *rangesY.find({p, p});
                    LOG("over", p, l, r);
                    if (K == 0) {
                        std::cout << val << '\n';
                        return;
                    }
                    K--;
                    LOG(K);
                }
                rangesN.emplace(p, p);
            } else {
                //if (rangesY.contains({p, p})) continue;
                if (lastL == -1) {
                    lastL = lastR = p;
                } else {
                    if (rangesN.contains({std::min(lastL, p), std::max(lastR, p)})) {
                        LOG(rangesY.contains({lastL - 1, lastR + 1}));
                        if (!rangesY.contains({lastL - 1, lastR + 1})) {
                            if (K == 0) {
                                std::cout << lastVal << '\n';
                                return;
                            }
                            K--;
                        }
                        LOG(K);
                        if (rangesY.contains({lastL, lastR})) {
                            auto it = rangesY.find({lastL, lastR});
                            lastL = std::min(lastL, it->first);
                            lastR = std::max(lastR, it->second);
                            rangesY.erase({lastL, lastR});
                        }
                        rangesY.emplace(lastL, lastR);
                        LOG(lastL, lastR);
                        lastL = lastR = p;
                        lastVal = val;
                    } else {
                        lastL = std::min(lastL, p);
                        lastR = std::max(lastR, p);
                    }
                }
            }
            lastVal = std::max(lastVal, val);
        }
        if (lastL != -1) {
            LOG(rangesY.contains({lastL - 1, lastR + 1}), lastL, lastR);
            if (!rangesY.contains({lastL - 1, lastR + 1})) {
                if (K == 0) {
                    std::cout << lastVal << '\n';
                    return;
                }
                K--;
            }
            LOG(K);
            if (rangesY.contains({lastL, lastR})) {
                auto it = rangesY.find({lastL, lastR});
                lastL = std::min(lastL, it->first);
                lastR = std::max(lastR, it->second);
                rangesY.erase({lastL, lastR});
            }
            rangesY.emplace(lastL, lastR);
            LOG(lastL, lastR);
        }
    }
    std::cout << 0 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}