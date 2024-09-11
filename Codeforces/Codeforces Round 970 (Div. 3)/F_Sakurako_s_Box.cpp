#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

i64 qmi(i64 a, i64 k, i64 p)
{
    i64 res = 1;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

i64 get(i64 a,i64 p){
    if(a % p == 0) return -1;
    else  return qmi(a,p-2,p);
}

void solve()
{
    int n; // 2E5
    std::cin >> n;
    std::vector<int> vec(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i]; // 1E9
        sum += vec[i];
    }
    i64 xsum = 0;
    i64 r = get((1LL*n*(n-1)/2), 1000000007LL);
    for (int i = 0; i < n - 1; i++) {
        sum -= vec[i];
        xsum += (1LL * vec[i] * (sum % 1000000007LL)  * r);
    }
    
    std::cout << (xsum % 1000000007LL) << std::endl;
    
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