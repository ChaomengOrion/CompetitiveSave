#include <bits/stdc++.h>

using i64 = long long;

#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;

int count = 0;
void solve()
{
    int n;
    std::string s;
    cin >> n;
    std::vector<char> strs(n);

    std::string ans = "";
    char last = 0;
    while (!strs.empty())
    {
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i] != last)
            {
                last = strs[i];
                ans += last;
                strs.erase(strs.begin() + i);
            }
            else if (i == strs.size() - 1)
            {
                last = strs[0];
                ans += last;
                strs.erase(strs.begin());
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}