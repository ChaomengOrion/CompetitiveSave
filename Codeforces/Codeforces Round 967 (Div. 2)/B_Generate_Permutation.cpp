#include <bits/stdc++.h>

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

#define string std::string
#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;
#define OUT(n) cout << n;

void solve()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        string out;
        for (int i = 0; i < (n+1)/2; i++)
        {
            out += std::to_string(i*2+1) + ' ';
        }
        for (int i = (n-1)/2; i > 0; i--)
        {
            out += std::to_string(i*2);
            if (i != 1) out += ' ';
        }
        cout << out << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}