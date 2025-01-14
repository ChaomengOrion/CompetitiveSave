#include <bits/stdc++.h>

struct node {
    int s, h;
};

std::stack<node> q;
int z[100012], r[100012];
int h[100012], ans;

void clean() {
    while (!q.empty()) q.pop();
}

int main() {
    int i, j;
    int n;
    std::cin >> n;
    for (i = 1; i <= n; i++) {
        std::cin >> h[i];
    }

    for (i = 1; i <= n; i++) {
        while (!q.empty() && q.top().h < h[i]) q.pop();
        if (!q.empty())
            z[i] = q.top().s;
        else
            z[i] = 0;
        node t;
        t.h = h[i];
        t.s = i;
        q.push(t);
    }
    clean();
    for (i = n; i >= 1; i--) {
        while (!q.empty() && q.top().h > h[i]) q.pop();
        if (!q.empty())
            r[i] = q.top().s;
        else
            r[i] = n + 1;
        node t;
        t.h = h[i];
        t.s = i;
        q.push(t);
    }

    for (i = n; i >= 1; i--) {
        for (j = z[i] + 1; j < i; j++) {
            if (r[j] > i) {
                ans = std::max(ans, i - j + 1);
                break;
            }
        }
        if (i <= ans) break;
    }
    std::cout << ans;
    return 0;
}