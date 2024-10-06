#include <bits/stdc++.h>

using i64 = long long;

int cal(int a, int b, int l) {
    if (l <= 1) return 0;
    if (a > b) std::swap(a, b);
    int sa = std::max(1, l - b);
    int sb = sa - l + b + 1;
    return std::max(0, std::min(a - sa, b - sb) + 1);
}

void solve()
{
    int N, X, Y; // X+1 < Y
    std::cin >> N >> X >> Y;
    int L = N - (Y - X - 1); // 带上节点
    int C = Y - X + 1; // 环上节点
    int EC = C / 2; // 等效带
    int CL = X - 1, CR = N - Y;
    for (int i = 1; i <= N - 1; i++) {
        int cntL = std::max(0, (L - i));
        int cntC = i <= EC ? C : 0;
        if (i == 1) cntC--;
        int cntCR = cal(EC, CR, i) * 2;
        if (i >= 2 && i <= cntCR + 1) cntCR--;
        int cntCL = cal(EC, CL, i) * 2;
        if (i >= 2 && i <= cntCL + 1) cntCL--;
        std::cout << cntL + cntC + cntCR + cntCL<< std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}