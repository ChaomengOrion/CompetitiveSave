#include <bits/stdc++.h>

// TODO

int f[40010]; // 20000*2,分两类的种类并查集开两倍空间

struct node {
    int x, y, v;
} a[100010];

bool cmp(node x, node y)
{
    return x.v > y.v;
}

int find(int x)
{ // 查
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{ // 并
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
    }
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].v;
    }
    std::sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= n * 2; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (find(a[i].x) == find(a[i].y)) {
            std::cout << a[i].v; //* 矛盾
            return;
        }
        merge(a[i].x + n, a[i].y); //* 合并x的假想敌和y
        merge(a[i].x, a[i].y + n); //* 合并x和y的假想敌
    }
    std::cout << 0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}