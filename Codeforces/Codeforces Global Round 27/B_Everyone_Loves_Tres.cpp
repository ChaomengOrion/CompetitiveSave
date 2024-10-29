#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    if (N == 1 || N == 3) {
        std::cout << -1 << std::endl;
    } else {
        if (N % 2) {
            std::string s;
            for (int i = 0; i < N - 4; i++) {
                s += '3';
            }
            s += "6366";
            std::cout << s << std::endl;
        } else {
            std::string s;
            for (int i = 0; i < N - 2; i++) {
                s += '3';
            }
            s += "66";
            std::cout << s << std::endl;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}