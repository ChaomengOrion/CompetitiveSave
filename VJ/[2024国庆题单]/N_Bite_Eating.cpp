#include <bits/stdc++.h>

void solve()
{
    int N, L;
    std::cin >> N >> L;
    int sum = (L + L + N - 1) * N / 2;
    if (L > 0) sum -= L;
    else if (L + N - 1 < 0) sum -= L + N - 1;
    std::cout << sum << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}