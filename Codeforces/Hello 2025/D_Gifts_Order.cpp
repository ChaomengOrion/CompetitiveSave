#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template<class InfoT>
struct SGT {
    std::vector<InfoT> tree;
    int size;

    inline int lson(int p) { return p << 1; } //* 左子节点

    inline int rson(int p) { return p << 1 | 1; } //* 右子节点

    void pull_up(int p) { //* 用子节点Info更新父节点
        tree[p] = tree[lson(p)] + tree[rson(p)];
    }

    template<class T>
    SGT(std::vector<T>& source) {
        size = source.size() - 1;
        int bottom = 1;
        while (bottom < size) bottom <<= 1;
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
    
    //* 区间查询
    InfoT query(int L, int R) {
        auto search = [&](auto&& self, int p, int curL, int curR) -> InfoT {
            if (L <= curL && curR <= R) return tree[p];
            InfoT res;
            int mid = (curL + curR) >> 1; //? [curL, mid], [mid+1, curR]中一定有至少一个与[L, R]有交集
            bool flag = false;
            if (L <= mid) res = self(self, lson(p), curL, mid), flag = true;
            if (R >= mid + 1) res = flag ? res + self(self, rson(p), mid + 1, curR) : self(self, rson(p), mid + 1, curR);
            return res;
        };
        return search(search, 1, 1, size);
    }

    //* 单点修改
    void modify(int pos, const InfoT& newVal) {
        auto update = [&](auto&& self, int p, int curL, int curR) -> void {
            if (curR == curL && curR == pos) {
                tree[p] = newVal;
                return;
            }
            int mid = (curL + curR) >> 1;
            if (pos <= mid) self(self, lson(p), curL, mid);
            else self(self, rson(p), mid + 1, curR);
            pull_up(p);
        };
        update(update, 1, 1, size);
    }

    //* 单点修改（使用Delta）
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
    int ans;
    int lmax, lmin, rmax, rmin;

    Info() = default; //* 无参初始化（重置时候用）
    Info(int val, int pos) : lmax(val + pos), rmin(val + pos), lmin(val - pos), rmax(val - pos), ans(0) {}
};

Info operator+(const Info& a, const Info& b) { //* 合并操作，a左b右
    Info ans;
    ans.lmax = std::max(a.lmax, b.lmax);
    ans.rmax = std::max(a.rmax, b.rmax);
    ans.lmin = std::min(a.lmin, b.lmin);
    ans.rmin = std::min(a.rmin, b.rmin);
    ans.ans = std::max({
        a.ans,
        b.ans,
        a.lmax - b.rmin,
        b.rmax - a.lmin
    });
    return ans;
}

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<Info> arr(N + 1);
    
    for (int i = 1; i <= N; i++) {
        int val;
        std::cin >> val;
        arr[i] = Info(val, i);
    }
    SGT<Info> sgt(arr);
    std::cout << sgt.query(1, N).ans << std::endl;
    while (Q--) {
        int pos, newVal;
        std::cin >> pos >> newVal;
        sgt.modify(pos, Info(newVal, pos));
        std::cout << sgt.query(1, N).ans << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}