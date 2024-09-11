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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve()
{
    int n, q;
    cin >> n >> q; // n: cities q: queries
    std::vector<char> colors(n);
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 'B') {
                colors[i] |= 1 << 0;
            }
            else if (c == 'G') {
                colors[i] |= 1 << 1;
            }
            else if (c == 'R') {
                colors[i] |= 1 << 2;
            }
            else if (c == 'Y') {
                colors[i] |= 1 << 3;
            }
        }
    }

#pragma region RL
        std::vector<int> toRight(n); // ==>
        std::vector<int> toLeft(n); // <==
        toRight[n-1] = toLeft[0] = -1;

        for (int i = 0; i < n-1; i++)
        {
            if (colors[i+1] == colors[i] or (colors[i+1] & colors[i]) == 0)
            {
                toLeft[i+1] = toLeft[i];
            }
            else
            {
                toLeft[i+1] = i;
            }
        }
        
        for (int i = n-1; i > 0; i--)
        {
            if (colors[i-1] == colors[i] or (colors[i-1] & colors[i]) == 0)
            {
                toRight[i-1] = toRight[i];
            }
            else
            {
                toRight[i-1] = i;
            }
        }
#pragma endregion

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) std::swap(x, y); // x < y
        if ((colors[x] & colors[y]) != 0)
        {
            cout << y - x << endl;
            continue;
        }

        int r = toRight[x];
        if (r != -1 and r < y)
        {
            cout << y - x << endl;
        }
        else
        {
            int l = toLeft[x];
            if (l != -1 && r != -1)
            {
                cout << std::min(std::abs(x-l) + std::abs(y-l), std::abs(x-r) + std::abs(y-r)) << endl;
            }
            else if(l == -1 && r == -1)
            {
                cout << -1 << endl;
            }
            else if (r == -1)
            {
                cout << std::abs(x-l) + std::abs(y-l) << endl;
            }
            else
            {
                cout << std::abs(x-r) + std::abs(y-r) << endl;
            }
        }
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