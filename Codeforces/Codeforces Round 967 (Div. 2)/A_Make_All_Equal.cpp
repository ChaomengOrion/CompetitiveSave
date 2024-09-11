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
    if (n == 1)
    {
        int num0;
        cin >> num0;
        cout << 0 << endl;
        return;
    }
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    int max = 1, curCount = -1, cur = -1;
    for (int i = 0; i < n; i++)
    {
        int item = arr[i];
        if (item != cur)
        {
            cur = item;
            curCount = 1;
        }
        else
        {
            curCount++;
            if (curCount > max)
            {
                max = curCount;
            }
        }
    }
    cout << n - max << endl;
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