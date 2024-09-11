#include <bits/stdc++.h>

using i64 = long long;

#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;

int  count = 0;
void solve()
{
    int    n;
    std::string s;
    cin >> n;
    std::vector<char>             strs(n);
    std::unordered_map<char, int> charCount;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
        charCount[strs[i]]++;
    }

    std::string ans  = "";
    char   last = 0;
    while (!strs.empty())
    {
        int maxCount = -1;
        int maxIndex = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i] != last)
            {
                int count = charCount[strs[i]];
                if (count > maxCount)
                {
                    maxCount = count;
                    maxIndex = i;
                }
            }
            if (i == strs.size() - 1)
            {
                if (maxIndex != -1)
                {
                    last = strs[maxIndex];
                    ans += last;
                    strs.erase(strs.begin() + maxIndex);
                    charCount[last]--;
                    break;
                }
                else
                {
                    last = strs[0];
                    ans += last;
                    strs.erase(strs.begin());
                    charCount[last]--;
                    break;
                }
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