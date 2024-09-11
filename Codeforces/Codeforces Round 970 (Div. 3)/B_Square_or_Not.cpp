#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    if (s == "1111") {
        std::cout << "Yes" << std::endl;
        return;
    }

    if (s.find('0') == std::string::npos) {
        std::cout << "No" << std::endl;
        return;
    }

    int width = -1, height = -1;
    for (int i = 0; i < n; i++) {
        if (width == -1 && s[i] == '0') {
            width = i - 1;
            if (width < 3 || n % width) {
                std::cout << "No" << std::endl;
                return;
            }
            height = n / width;
            if (height != width) {
                std::cout << "No" << std::endl;
                return;
            }

        } else if (width != -1) {
            char c;
            if (i % width == width-1 || i % width == 0) {
                c = '1';
            } else if (i >= n - width) {
                c = '1';
            } else {
                c = '0';
            }
            if (s[i] != c) {
                std::cout << "No" << std::endl;
                return;
            }
        }
    }
    std::cout << "Yes" << std::endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}