#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cerr << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cerr << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n-1);
    int pre;
    std::cin >> pre;
    for (int i = 0; i < n - 1; i++) {
        int input;
        std::cin >> input;
        vec[i] = abs(input - pre);
        pre = input;
    }
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < n - 1; i++) {
        if (vec[i] != i + 1) {
            std::cout << "Not jolly" << std::endl;
            return;
        }
    }

    std::cout << "Jolly" << std::endl;
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