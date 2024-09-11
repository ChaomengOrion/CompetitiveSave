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

struct Node
{
    int id, nextid, preid;
    int data;
} node[105];


void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int num0;
        cin >> num0;
        cout << 0 << endl;
        return;
    }
    // n >= 2
    node[0].id = 0;
    node[0].preid = n - 1;
    node[0].nextid = 1;
    cin >> node[0].data;
    for (int i = 1; i < n - 1; i++)
    {
        node[i].id = i;
        node[i].preid = i - 1;
        node[i].nextid = i + 1;
        cin >> node[i].data;
    }
    node[n-1].id = n-1;
    node[n-1].preid = n-2;
    node[n-1].nextid = 0;
    cin >> node[n-1].data;
    
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