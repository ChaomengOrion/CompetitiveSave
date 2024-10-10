#include <bits/stdc++.h>

bool vis[10];

bool check(int n)
{
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int c = n % 10;

    if (vis[a] || vis[b] || vis[c]) {
        for (int i = 0; i < 10; i++) vis[i] = false;
        return false;
    }

    bool ok = a != b && b != c && a != c && a * b * c != 0;
    // 是否满足三位数不一样
    if (ok) vis[a] = vis[b] = vis[c] = true; // 标记访问过该数字
    else for (int i = 0; i < 10; i++) vis[i] = false;

    return ok;
}

int main()
{
    for (int first = 123; first <= 333; first++) {
        if (!check(first) || !check(first * 2) || !check(first * 3)) continue;
        std::cout << first << ' ' << first * 2 << ' ' << first * 3 << std::endl;
    }
}