#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

class TreeArray
{
private:
    int size;
    std::vector<int> arr;

public:
    TreeArray(int len) : size(len), arr(len + 1, 0) { }

    TreeArray(std::vector<int>& source) : size(source.size()), arr(size + 1, 0)
    {
        for (int i = 1; i <= size; i++) {
            add(i, source[i]);
        }
    }

    inline static int lowbit(int x) { return x & -x; }

    void add(int pos, int value)
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

int main()
{
    std::vector<int> test = {0, 2, 3, 0, 4, 5};
    TreeArray tr(test);
    std::cout << tr.query(1) << std::endl;
    std::cout << tr.query(2) << std::endl;
    std::cout << tr.query(3) << std::endl;
    std::cout << tr.query(4) << std::endl;
    std::cout << tr.query(5) << std::endl;
    tr.add(3, -3);
    std::cout << tr.query(1) << std::endl;
    std::cout << tr.query(2) << std::endl;
    std::cout << tr.query(3) << std::endl;
    std::cout << tr.query(4) << std::endl;
    std::cout << tr.query(5) << std::endl;
    tr.add(4, 1000 - tr.query(4, 4));
    std::cout << tr.query(3, 4) << std::endl;
}