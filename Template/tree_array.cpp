#include <bits/stdc++.h>
using i64 = long long;
class TreeArray
{
private:
    int size;
    std::vector<int> arr;
public:
    TreeArray(int len) : size(len), arr(len + 1, 0) { }

    TreeArray(std::vector<int>& source) : size(source.size() - 1), arr(size + 1, 0)
    {
        for (int i = 1; i <= size; i++) {
            add(i, source[i]);
        }
    }
    inline static int lowbit(int x) { return x & -x; }
    void add(int pos, int value) // 第pos项加value
    {
        while (pos <= size) {
            arr[pos] += value;
            pos += lowbit(pos);
        }
    }
    i64 query(int pos) // 查询[1,pos]项的和
    {
        i64 sum = 0;
        while (pos >= 1) {
            sum += arr[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }
    i64 query(int l, int r) { return query(r) - query(l - 1); } // 查询[l,r]项的和
};