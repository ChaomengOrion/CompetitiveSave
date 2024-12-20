#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mt19937_64 rnd(1);

    ll i, j;
    const ll x = 196560;

    ll n = 200000, m = 200000, q = 50000;

    set<ll> s;
    vector<ll> a, b;
    ll sum = 0;
gg:
    while (a.size() < n - 1) {
        ll k;
        if (sum < 0) {
            k = rnd() % 200000 + 1;
            while (x % k == 0 || s.count(k)) k = rnd() % 200000 + 1;
        } else {
            k = -(rnd() % 200000 + 1);
            while (x % k == 0 || s.count(k)) k = -(rnd() % 200000 + 1);
        }
        a.push_back(k);
        s.insert(k);
        sum += k;
    }
    if (x % sum == 0 || s.count(-sum)) {
        s.erase(a.back());
        sum -= a.back();
        a.pop_back();
        goto gg;
    }
    a.push_back(-sum);

    s.clear();

    for (i = 1; i <= x; i++)
        if (x % i == 0) b.push_back(i), b.push_back(-i), s.insert(i), s.insert(-i);

    sum = 0;
gg2:
    while (b.size() < n - 1) {
        ll k;
        if (sum < 0) {
            k = rnd() % 200000 + 1;
            while (s.count(k)) k = rnd() % 200000 + 1;
        } else {
            k = -(rnd() % 200000 + 1);
            while (s.count(k)) k = -(rnd() % 200000 + 1);
        }
        b.push_back(k);
        s.insert(k);
        sum += k;
    }
    if (x % sum == 0 || s.count(-sum)) {
        s.erase(b.back());
        sum -= b.back();
        b.pop_back();
        goto gg2;
    }
    b.push_back(-sum);

    shuffle(b.begin(), b.end(), rnd);

    if (argv[1][0] == '2') swap(a, b);

    cout << n << ' ' << m << ' ' << q << '\n';
    for (i = 0; i < n; i++) cout << b[i] << (i == n - 1 ? '\n' : ' ');
    for (i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? '\n' : ' ');
    while (q--) cout << x << '\n';
}