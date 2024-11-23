#include <bits/stdc++.h>
using i64 = long long;

template <class T, class Merge = std::plus<T>>
struct BIT {
    const Merge merge;
    std::vector<T> t;

    BIT(int n) : t(n + 1), merge(Merge()) {}

    // O(n) build BIT
    BIT(const std::vector<T>& a) : BIT(a.size()) {
        int n = a.size();
        for (int i = 1; i <= n; i++) {
            t[i] = merge(t[i], a[i - 1]);
            int j = i + (i & -i);
            if (j <= n)
                t[j] = merge(t[j], t[i]);
        }
    }

    void add(int i, const T &x) {
        for (i += 1; i < t.size(); i += i & -i)
            t[i] = merge(t[i], x);
    }

    T posQuery(int i)  {
        T res = T();
        for (i += 1; i; i -= i & -i)
            res = add(res, t[i]);
        return res;
    }

    T rangeQuery(int l, int r)  { // [l, r]
        return posQuery(r) - posQuery(l - 1);
    }
};