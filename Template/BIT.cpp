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

template<typename T>
class TreeArray
{
private:
    int size;
    std::vector<T> arr;

public:
    TreeArray(int len) : size(len), arr(len + 1, 0) { }

    TreeArray(std::vector<T>& source) : size(source.size()), arr(size + 1, 0)
    {
        for (int i = 1; i <= size; i++) {
            add(i, source[i]);
        }
    }

    inline static int lowbit(int x) { return x & -x; }

    void add(int pos, T value)
    {
        while (pos <= size) {
            arr[pos] += value;
            pos += lowbit(pos);
        }
    }

    i64 query(int pos)
    {
        i64 sum = 0;
        while (pos >= 1) {
            sum += arr[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }

    i64 query(int l, int r) { return query(r) - query(l - 1); }
};

const int MOD = 1e9+7;

template<typename T>
class TreeArrayMOD
{
private:
    int size;
    std::vector<T> arr;

public:
    TreeArrayMOD(int len) : size(len), arr(len + 1, 0) { }

    inline static int lowbit(int x) { return x & -x; }

    void add(int pos, T value)
    {
        if (pos < 1) return;
        value += MOD; value %= MOD;
        while (pos <= size) {
            arr[pos] += value;
            arr[pos] %= MOD;
            pos += lowbit(pos);
        }
    }

    i64 query(int pos)
    {
        i64 sum = 0;
        while (pos >= 1) {
            sum += arr[pos];
            sum %= MOD;
            pos -= lowbit(pos);
        }
        return sum;
    }

    i64 query(int l, int r) { return (query(r) - query(l - 1) + MOD) % MOD; }

    [[maybe_unused]] void debug() {
        std::cerr << "BIT: [";
        for (int i = 1; i <= size; i++) {
            std::cerr << query(i, i) << ", ";
        }
        std::cerr << "]\n";
    }
};