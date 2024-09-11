#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    if (n & 1 ^ 1) {
        std::vector<int> odd(26, 0);
        std::vector<int> even(26, 0);
        for (int i = 0; i < n; i++) {
            if (i & 1 ^ 1) {
                odd[s[i] - 'a']++;
            } else {
                even[s[i] - 'a']++;
            }
        }
        std::cout << n - *std::max_element(odd.begin(), odd.end()) - *std::max_element(even.begin(), even.end()) << std::endl;
    } else {
        std::vector pre_even(26, std::vector<int>(n+1, 0));
        std::vector pre_odd(26, std::vector<int>(n+1, 0));
        for (int i = 0; i < n; i++) {
            auto& p = i & 1 ^ 1 ? pre_odd : pre_even;
            auto& p2 = i & 1 ? pre_odd : pre_even;
            for (int j = 0; j < 26; j++) {
                if (j == s[i] - 'a') {
                    p[j][i+1] = p[j][i] + 1;
                } else {
                    p[j][i+1] = p[j][i];
                }
                p2[j][i+1] = p2[j][i];
            }
        }
        int max = -1;
        for (int d = 0; d < n; d++) {
            std::vector<int> odd(26);
            std::vector<int> even(26);
            for (int i = 0; i < 26; i++) {
                odd[i] = pre_odd[i][d] - pre_odd[i][0] + pre_even[i][n] - pre_even[i][d+1];
                even[i] = pre_even[i][d] - pre_even[i][0] + pre_odd[i][n] - pre_odd[i][d+1];
            }
            max = std::max(max, *std::max_element(odd.begin(), odd.end()) + *std::max_element(even.begin(), even.end()));
        }
        std::cout << n - max << std::endl;
    }
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