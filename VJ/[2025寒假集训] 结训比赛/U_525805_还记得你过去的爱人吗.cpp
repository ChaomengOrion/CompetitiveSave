#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template<class InfoT>
struct SGT {
    std::vector<InfoT> tree;
    int size;

    inline int lson(int p ) { return  p << 1; }
    inline int rson(int p ) { return  p << 1 | 1; }

    void pull_up(int p) {
        tree[p] = tree[lson(p)] + tree[rson(p)];
    }

    template<class T>
    SGT(std::vector<T>& source) {
        size = source.size() - 1;
        int bottom = 1;
        while (bottom < size) {
            bottom <<= 1;
        }
        tree.resize(bottom << 1);
        auto build = [&](auto&& self, int p, int curL, int curR) -> void {
            if (curL == curR) {
                tree[p] = source[curL];
                return;
            }
            int mid = (curL + curR) >> 1;
            self(self, lson(p), curL, mid);
            self(self, rson(p), mid + 1, curR);
            pull_up(p);
        };
        build(build, 1, 1, size);
    }
    InfoT query(int L, int R) {
        auto search = [&](auto&& self, int p, int curL, int curR) -> InfoT {
            if (L <= curL && curR <= R) return tree[p];
            InfoT res;
            int mid = (curL + curR) >> 1;
            bool flag = false;
            if (L <= mid) res = self(self, lson(p), curL, mid), flag = true;
            if (R >= mid + 1) res = flag ? res + self(self, rson(p), mid + 1, curR) : self(self, rson(p), mid + 1, curR);
            return res;
        };
        return search(search, 1, 1, size);
    }
    template<class DeltaT>
    void modify(int pos, const DeltaT& delta) {
        auto update = [&](auto&& self, int p, int curL, int curR) -> void {
            if (curR == curL && curR == pos) {
                delta.applyTo(tree[p]);
                return;
            }
            int mid = (curL + curR) >> 1;
            if (pos <= mid) self(self, lson(p), curL, mid);
            else self(self, rson(p), mid + 1, curR);
            pull_up(p);
        };
        update(update, 1, 1, size);
    }
};

struct Info {
    i64 max, sum;
    i64 lmax, rmax;
    Info() = default;
    Info(int v) {
        sum = max = lmax = rmax = v;
    } 
    static i64 merge(int a, int b) {
        if (a >= 0 && b >= 0) return a + b;
        if (a >= 0 && b < 0) return a;
        if (a < 0 && b >= 0) return b;
        return std::max(a, b);
    }
    friend Info operator+(const Info& a, const Info& b) {
        Info ans;
        ans.sum = a.sum + b.sum;
        i64 midmax = merge(a.rmax, b.lmax);
        ans.lmax = std::max(a.lmax, a.sum + b.lmax);
        ans.rmax = std::max(b.rmax, b.sum + a.rmax);
        ans.max = std::max({a.max, b.max, ans.lmax, ans.rmax, midmax, ans.sum});
        return ans;
    }
};

struct Delta {
    i64 val;
    void applyTo(Info& info) const {
        info = Info(val);
    }
};

void solve() {
    i64 N, Q;
    std::cin >> N >> Q;
    std::vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    SGT<Info> sgt(arr);
    while (Q--) {
        i64 op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1) {
            if (x > y) std::swap(x, y);
            auto ans = sgt.query(x, y);
            std::cout << ans.max << std::endl;
        } else {
            Delta d;
            d.val = y;
            sgt.modify(x, d);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}