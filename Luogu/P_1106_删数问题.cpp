#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    while (k--)
    {
        int i = 0;
        while (i + 1 < s.length() && s[i] <= s[i + 1]) i++;
        s.erase(i, 1);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0')
        {
            s = s.substr(i);
            break;
        }
        if (i == s.length()-1) s = '0';
    }
    std::cout << s << std::endl;
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