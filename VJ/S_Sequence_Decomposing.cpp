#include <bits/stdc++.h>

int p[100100];
int t[100010], ct = 1;

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int temp = upper_bound(t + 1, t + ct, p[i], std::greater<int>()) - t;
        if (temp == ct)
            t[ct++] = p[i];
        else
            t[temp] = p[i];
    }
    std::cout << ct - 1 << std::endl;
    return 0;
}