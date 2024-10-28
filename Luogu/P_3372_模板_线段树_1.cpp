#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> diff(N + 1, 0);
    std::vector<i64> diff2(N + 1, 0);
    int last = 0;
    for (int i = 1; i <= N; i++) {
        int temp;
        std::cin >> temp;
        diff[i] = temp - last;
        diff2[i] = 1LL * (i - 1) * diff[i];
        last = temp;
    }

    TreeArray<int> tr1(diff);
    TreeArray<i64> tr2(diff2);
    // pre[i] = k*Σ(D[i]) - Σ((i-1)*D[i])
    while (M--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            tr1.add(x, k);
            tr1.add(y + 1, -k);
            tr2.add(x, 1LL * (x - 1) * k);
            tr2.add(y + 1, -1LL * y * k);
        } else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            i64 sum1 = 1LL * y * tr1.query(y) - tr2.query(y);
            i64 sum2 = 1LL * (x - 1) * tr1.query(x - 1) - tr2.query(x - 1);
            std::cout << sum1 - sum2 << std::endl;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}