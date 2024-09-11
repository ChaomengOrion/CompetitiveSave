#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

struct Node {
    int id;
    int pre, next;
};

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Node> list(n);
    for (int i = 0; i < n; i++) {
        list[i].id = i + 1;
        list[i].next = (i + 1 + n) % n;
        list[i].pre = (i - 1 + n) % n;
    }
    int now = 0;
    while (n--) {
        int cnt = 1;
        while (cnt++ < m) now = list[now].next;
        std::cout << list[now].id << ' ';
        list[list[now].next].pre = list[now].pre;
        list[list[now].pre].next = list[now].next;
        now = list[now].next;
    }
    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}