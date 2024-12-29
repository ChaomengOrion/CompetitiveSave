#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> partten(n);
    for (int i = 0; i < n; i++) {
        std::cin >> partten[i];
    }

    int m;
    std::cin >> m;

    std::unordered_map<char, int> map;
    std::unordered_map<int, char> rmap;

    while (m--) {
        std::string s;
        std::cin >> s;
        map.clear();
        rmap.clear();
        if (s.length() != n) {
            std::cout << "NO" << std::endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if ((map.contains(s[i]) && map.at(s[i]) != partten[i]) 
            || (rmap.contains(partten[i]) && rmap.at(partten[i]) != s[i]))
            {
                std::cout << "NO" << std::endl;
                break;
            }
            else
            {
                map[s[i]] = partten[i];
                rmap[partten[i]] = s[i];
            }

            if (i == n-1) std::cout << "YES" << std::endl;
        }
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