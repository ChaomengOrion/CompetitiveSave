#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template<class InfoT, class TagT>
class LSGT {
public:
    struct Node {
        InfoT info = InfoT();
        TagT tag = TagT();
    };
    std::vector<Node> tree;
    int size;

    inline int lson(int p) { return p << 1; } //* 左子节点

    inline int rson(int p) { return p << 1 | 1; } //* 右子节点

    void addTag(int p, int curL, int curR, const TagT& delta) { //* 给代表[l,r]区间的Info打Tag
        tree[p].tag.applyTo(tree[p].info, curL, curR, delta);
    }

    void pull_up(int p) { //* 用子节点Info更新父节点
        tree[p].info = tree[lson(p)].info + tree[rson(p)].info;
    }
    
    template<class T>
    LSGT(std::vector<T>& source) {
        size = source.size() - 1;
        int bottom = 1;
        while (bottom < size) bottom <<= 1;
        tree.resize(bottom << 1);
        auto build = [&](auto&& self, int p, int curL, int curR) -> void {
            if (curL == curR) {
                tree[p].info = source[curL];
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
            if (L <= curL && curR <= R) return tree[p].info;
            InfoT res;
            int mid = (curL + curR) >> 1; //? [curL, mid], [mid+1, curR]中一定有至少一个与[L, R]有交集
            bool flag = false;
            if (L <= mid) res = self(self, lson(p), curL, mid), flag = true;
            if (R >= mid + 1) res = flag ? res + self(self, rson(p), mid + 1, curR) : self(self, rson(p), mid + 1, curR);
            return res;
        };
        return search(search, 1, 1, size);
    }

    void modify(int L, int R, const TagT& delta) {
        auto update = [&](auto&& self, int p, int curL, int curR) -> void {
            if (L <= curL && curR <= R) {
                if (curL == curR) {
                    addTag(p, curL, curR, delta);
                    return;
                }
                else if (!delta.needDown(tree[p].info)) return;
                else {
                    int mid = (curL + curR) >> 1;
                    self(self, lson(p), curL, mid);
                    self(self, rson(p), mid + 1, curR);
                    pull_up(p);
                }
            } else {
                int mid = (curL + curR) >> 1;
                if (L <= mid) self(self, lson(p), curL, mid);
                if (R >= mid + 1) self(self, rson(p), mid + 1, curR);
                pull_up(p);
            }
        };
        update(update, 1, 1, size);
    }
};

struct Info {
    i64 sum;
    bool one;
    Info() = default; //* 无参初始化（重置时候用）
    Info(i64 v) : sum(v), one(v == 1) {} //? 从其他类型转换（Build时候用）
};

Info operator+(const Info& a, const Info& b) { //* 合并操作，a左b右
    Info ans;
    ans.sum = a.sum + b.sum;
    ans.one = a.one && b.one;
    return ans;
}

//! Only for LSGT
struct SqrtTag {
    SqrtTag() = default;//* 初始化（push_down结束重置时候用）
    bool isVaild() const { //* tag是否生效
        return false;
    }
    bool needDown(Info& info) const {
        return !info.one;
    }
    void applyTo(Info& info, int l, int r, const SqrtTag& delta) { //* 对代表[l,r]区间的info打上tag
        info.sum = std::sqrt(info.sum);
        if (info.sum == 1) {
            info.one = true;
        }
    }
};

bool solve(int id) {
    int N;
    if (!(std::cin >> N)) {
        return false;
    }
    std::cout << "Case #" << id << ':' << std::endl;
    std::vector<i64> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    LSGT<Info, SqrtTag> sgt(arr);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 0) {
            sgt.modify(x, y, SqrtTag());
        } else {
            std::cout << sgt.query(x, y).sum << std::endl;
        }
    }
    return true;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int cnt = 1;
    while (true) {
        if (!solve(cnt++)) break;
        std::cout << std::endl;
    }
    return 0;
}