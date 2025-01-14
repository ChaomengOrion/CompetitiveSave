#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) //std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    int cost;
    int draws = 0;
    int lson, rson;
    std::vector<int> timeList;
};

void solve() {
    int L;
    std::cin >> L;
    std::vector<node> tree;
    int id = 0;
    auto dfs_build = [&](auto&& self) -> int {
        int cost, cnt;
        int curid = id++;
        std::cin >> cost >> cnt;
        if (cnt != 0) {
            tree.push_back({cost, cnt, -1, -1});
        } else {
            tree.push_back({cost, 0, -1, -1});
            int l = self(self), r = self(self);
            tree[curid].lson = l;
            tree[curid].rson = r;
        }
        return curid;
    };
    dfs_build(dfs_build);
    
    auto dfs = [&](auto&& self, int x) -> void {
        LOG("dfs to: " << x)
        if (tree[x].draws == 0) {
            self(self, tree[x].lson);
            self(self, tree[x].rson);
            //* 合并子节点dp
            std::vector<int> &al = tree[tree[x].lson].timeList, &bl = tree[tree[x].rson].timeList;
            tree[x].timeList.assign(al.size() + bl.size() - 1, INT_MAX);
            tree[x].timeList[0] = -1;
            for (int i = 1; i < al.size(); i++) {
                for (int j = 1; j < bl.size(); j++) {
                    tree[x].timeList[i + j] = std::min(tree[x].timeList[i + j], 2 * tree[x].cost + al[i] + bl[j]);
                }
            }
            for (int j = 1; j < al.size(); j++) {
                tree[x].timeList[j] = std::min(tree[x].timeList[j], 2 * tree[x].cost + al[j]);
            }
            for (int j = 1; j < bl.size(); j++) {
                tree[x].timeList[j] = std::min(tree[x].timeList[j], 2 * tree[x].cost + bl[j]);
            }
            LOG("走廊:")
            LOGV(tree[x].timeList, tree[x].timeList.size())
        } else {
            tree[x].timeList.assign(tree[x].draws + 1, -1);
            tree[x].timeList[1] = 2 * tree[x].cost + 5;
            for (int i = 2; i <= tree[x].draws; i++) {
                tree[x].timeList[i] = tree[x].timeList[i - 1] + 5;
            }
            LOG("叶子:")
            LOGV(tree[x].timeList, tree[x].timeList.size())
        }
    };

    dfs(dfs, 0);
    std::vector<int>& l = tree[0].timeList;
    int cnt = std::upper_bound(l.begin(), l.end(), L - 1) - l.begin() - 1;
    std::cout << cnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}