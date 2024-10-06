#include <bits/stdc++.h>

void solve()
{
    int P, Q, R;
    std::cin >> P >> Q >> R;
    if (P > Q) std::swap(P, Q);
    if (Q > R) std::swap(Q, R);
    if (P > R) std::swap(P, R);
    std::cout << P + Q << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}