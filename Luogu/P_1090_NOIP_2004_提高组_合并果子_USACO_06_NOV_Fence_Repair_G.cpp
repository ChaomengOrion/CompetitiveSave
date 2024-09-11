#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        queue.emplace(a);
    }
    int cnt = 0;
    while (queue.size() > 1) {
        int cur = queue.top();
        queue.pop();
        cur += queue.top();
        queue.pop();
        queue.emplace(cur);
        cnt += cur;
    }
    std::cout << cnt << std::endl;
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