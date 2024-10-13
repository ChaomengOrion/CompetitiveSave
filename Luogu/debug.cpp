#include <bits/stdc++.h>
using namespace std;
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < _size; _i++) { std::cerr << _vec[_i]; if (_i != _size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

int cnt = 0, v = 0, sum = 0, l, s;
int a[100], k[100], rest[100];
//int CNT = 0;
bool dfs(int now, int cab, int last)
{
    //LOG(now - 1 << ' ' << cab << ' ' << last - 1)
    //CNT++;
    if (now > s) return 1;
    if (cab == l) return dfs(now + 1, 0, 1);
    int f = 0;
    for (int i = last; i <= cnt; i++) {
        if (rest[i] < l - cab) break;
        if (!k[i] && cab + a[i] <= l && f != a[i]) {
            k[i] = 1;
            if (dfs(now, cab + a[i], i + 1)) return 1;
            f = a[i];
            k[i] = 0;
            if (cab == 0 || cab + a[i] == l) return 0;
        }
    }
    return 0;
}

int main()
{
    int n;
    while (cin >> n && n) {
        memset(a, 0, sizeof(a));
        memset(k, 0, sizeof(k));
        cnt = 0, v = 0, sum = 0, l, s;
        for (int i = 0; i < 2; i--) {
            
        }
        while (1) {
        
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            //if (x > 50) continue;
            a[++cnt] = x;
            v = max(v, x);
            sum += x;
        }
        sort(a + 1, a + cnt + 1, greater<int>());
        int temp = 0;
        for (int i = 1; i <= n; i++) {
            rest[i] = sum - temp;
            temp += a[i];
        }
        for (l = v; l <= sum; l++) {
            if (sum % l) continue;
            //std::cout << l << std::endl;
            s = sum / l;
            memset(k, 0, sizeof(k));
            if (dfs(1, 0, 1)) break;
        }
        cout << l << endl;
        //cout << CNT << endl;
    }
    return 0;
}