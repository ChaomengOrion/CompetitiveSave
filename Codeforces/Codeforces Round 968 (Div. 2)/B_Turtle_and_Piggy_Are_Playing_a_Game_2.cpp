#include <bits/stdc++.h>

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

#define string std::string
#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;

void solve()
{
    int n;
    cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());

    cout << vec[n/2] << endl;
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