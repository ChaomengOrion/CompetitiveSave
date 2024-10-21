#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::string s;
    std::cin >> s;
    char last = 0;
    for (int i = 0; i < N; i++) {
        char c = s[i];
        if ((i == 0 || i == N - 1) && c == '1') {
            std::cout << "YES" << std::endl;
            return;
        }
        if (c == '1' && last == '1') {
            std::cout << "YES" << std::endl;
            return;
        }
        last = c;
    }
    std::cout << "NO" << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}