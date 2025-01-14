#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            a[min(i - j, abs(x - j) + abs(y - i) + 1)]++;
        }
    }
    for (int i = 1; i <= n - 1; i++) cout << a[i] << endl;
}
