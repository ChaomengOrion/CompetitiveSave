#include <bits/stdc++.h>

struct node {
    std::vector<int> to;
    int parent = -1;
    std::vector<int> sons;
    int sonCnt = 0, curSonCnt = 0;
};

void solve()
{
    int n; // 3≤n≤5⋅10^5
    std::cin >> n;
    std::vector<node> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].to.push_back(b);
        tree[b].to.push_back(a);
    }

    std::vector<std::vector<int>> depthToNode(n);
    int max_depth = INT_MIN;

    auto build = [&](auto build, int p, int id, int depth) -> int {
        tree[id].parent = p;
        depthToNode[depth].push_back(id);
        max_depth = std::max(max_depth, depth);
        int cnt = 0;
        for (int son : tree[id].to) {
            if (son == p) continue;
            tree[id].sons.push_back(son);
            ++cnt += build(build, id, son, depth + 1);
        }
        tree[id].sonCnt = cnt;
        tree[id].curSonCnt = tree[id].sons.size();
        return cnt;
    };

    build(build, -1, 1, 0);

    int min_cost = INT_MAX, pre_cost = 0;
    for (int d = 1; d <= max_depth; d++) {
        for (int cur : depthToNode[d - 1]) { // 删除上一层所有深度不满足的叶子节点，并计算代价
            while (tree[cur].curSonCnt == 0) {
                cur = tree[cur].parent;
                tree[cur].curSonCnt--;
                pre_cost++;
            }
        }
        int sum = 0; // 计算删除超出深度的叶子节点数量
        for (int id : depthToNode[d]) {
            sum += tree[id].sonCnt;
        }
        min_cost = std::min(min_cost, sum + pre_cost);
    }

    std::cout << min_cost << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}