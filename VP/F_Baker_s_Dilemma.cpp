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

struct order {
    int day;
    int cost;
    int id;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<order> orders(N);
    for (int i = 0; i < N; i++) {
        std::cin >> orders[i].day >> orders[i].cost;
        orders[i].id = i + 1;
    }
    std::sort(orders.begin(), orders.end(), [](order& a, order& b) {
        if (a.day * b.cost == a.cost * b.day) {
            return a.id < b.id;
        }
        return a.day * b.cost < a.cost * b.day;
    });
    for (int i = 0; i < N; i++) {
        std::cout << orders[i].id << " \n"[i == N - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}