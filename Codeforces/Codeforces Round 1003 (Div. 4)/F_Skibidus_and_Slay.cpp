#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    int val;
    std::vector<int> to;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<node> tree(N + 1);
    std::vector<bool> ok(N + 1, false);
    for (int i = 1; i <= N; i++) {
        std::cin >> tree[i].val;
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        tree[u].to.emplace_back(v);
        tree[v].to.emplace_back(u);
    }
    for (int i = 1; i <= N; i++) {
        std::set<int> set { tree[i].val };
        for (int son : tree[i].to) {
            if (set.contains(tree[son].val)) {
                ok[tree[son].val] = true;
            } else {
                set.insert(tree[son].val);
            }
        }
    }
    std::string ans;
    for (int i = 1; i <= N; i++) {
        ans += '0' + (char)ok[i];
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}