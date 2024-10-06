#include <cmath>
#include <iostream>

using namespace std;
int q, k;
int s = 1e9 + 7;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> q >> k;
    int* st = new int[q + 1];
    for (int i = 1; i <= q; i++) cin >> st[i];
    int res = 1;
    int mi = 1 << (int)log2(k);
    if (mi == k) {
        for (int i = 1; i <= q; i++) {
            res = (1LL * (k + 1 - st[i]) * res) % s;
        }

    } else {
        int contest = k - mi;
        for (int i = 1; i <= q; i++) {
            if (st[i] <= contest || st[i] >= k + 1 - contest) {
                res = (1LL * (k + 1 - st[i]) * res) % s;
            } else {
                res = (1LL * (k + 1) * res) % s;
            }
        }
    }
    cout << res << endl;
}