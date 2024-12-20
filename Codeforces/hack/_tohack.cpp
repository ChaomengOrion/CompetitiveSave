#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define ld long double
#define CERR std::cerr << "[debug_line:" << __LINE__ << "]: "
 
using namespace std;
 
ll n, m, q, x, suma = 0, sumb = 0;

void solve()
{
 
    cin >> n >> m >> q;
    vector<bool> sa(2*n +3), sb(2*m +3);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        suma += x;
        sa[n + x] = 1;        
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
        sumb += x;
        sb[m + x] = 1;
    }
    //sa[n] -> 0
    for (int i = 1; i <= q; i++) {
        bool flag = 0;
        cin >> x;
 
        if (x == 0) {
            if ((abs(suma) <= n && sa[-suma + n]) || (abs(sumb) <= n && sb[-sumb + n])) {
                cout << "Yes" << endl;
                flag = 1;
            }
        } else {
            //
            for (int i = 1; i <= sqrt(abs(x)); i++) {
                if (x % i) continue;

                int x1 = i, x2 = x / i;
                if ((abs(suma - x1) <= n && abs(sumb - x2) <= m && sa[n + suma - x1] && sb[n + sumb - x2]) ||
                    (abs(suma - x2) <= n && abs(sumb - x1) <= m && sa[n + suma - x2] && sb[n + sumb - x1]) ||
                    (abs(suma + x1) <= n && abs(sumb + x2) <= m && sa[n + suma + x1] && sb[n + sumb + x2]) ||
                    (abs(suma + x2) <= n && abs(sumb + x1) <= m && sa[n + suma + x2] && sb[n + sumb + x1])) {
                    cout << "Yes" << endl;
                    flag = 1;
                    break;
                }
            }
            if(!flag) cout << "NO"<<endl;
        }
        
    }
}
 
int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
} 