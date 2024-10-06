#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    std::string s;
    std::cin >> s;

    if (s.size() == 1) {
        if (s[0] == '3' || s[0] == '6' || s[0] == '9') {
            std::cout << 0 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
        return;
    }

    std::array<int, 10> cnt = {};
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        sum += d;
        cnt[d]++;
    }

    if (sum % 3 == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    int rest = sum % 3;

    std::array<int, 3> need = {rest, rest + 3, rest + 6};
    for (int i = 0; i < 3; i++) {
        if (cnt[need[i]] > 0) {
            std::cout << 1 << std::endl;
            return;
        }
    }

    if (sum > 2) {
        if (rest == 1) {
            if (cnt[2] >= 2 || (cnt[2] >= 1 && cnt[5] >= 1)) {
                std::cout << 2 << std::endl;
                return;
            }
        } else if (rest == 2) {
            if (cnt[1] >= 2 || (cnt[1] >= 1 && cnt[4] >= 1) || cnt[4] >= 2) {
                std::cout << 2 << std::endl;
                return;
            }
        }
    }

    std::cout << -1 << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}