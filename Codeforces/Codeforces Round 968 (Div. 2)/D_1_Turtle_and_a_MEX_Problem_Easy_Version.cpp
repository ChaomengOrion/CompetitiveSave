#include <bits/stdc++.h>

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

#define string std::string
#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;
#define DEBUGI(i, n) cout << "DEBUG[" << i << "]: " << n << endl;

void solve()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> vecs(n);


    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        vecs[i] = std::vector<int>(len);
        for (int j = 0; j < len; j++)
        {
            cin >> vecs[i][j];
        }
        std::sort(vecs[i].begin(), vecs[i].end());
    }

    int max = -1;
    {
        for (auto vec : vecs)
        {
            bool skip = false;
            int  last = -1;

            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i] == last)
                {
                    if (i < vec.size() - 1) continue;
                }
                if (vec[i] == last + 1)
                {
                    last = vec[i];
                    if (i < vec.size() - 1) continue;
                }
                if (!skip)
                {
                    skip = true;
                    last += 1;
                    i--;
                    continue;
                }
                else break;
            }
            max = std::max(max, last + 1);
        }
    }


    i64 ans = 0;
    if (m <= max)
    {
        ans += 1LL * max * (m + 1); 
    }
    else
    {
        ans += 1LL * max * max; 
        ans += ((i64)max + (i64)m) * ((i64)m - (i64)max + 1) / 2;
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