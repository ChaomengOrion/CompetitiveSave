#include <bits/stdc++.h>
using i64 = long long;

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