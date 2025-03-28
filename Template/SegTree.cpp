#include <bits/stdc++.h>

using i64 = long long;

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

    void push_down(int p, int curL, int curR) { //* 下传Tag
        if (!tree[p].tag.isVaild()) return;
        int mid = (curL + curR) >> 1;
        addTag(lson(p), curL, mid, tree[p].tag);
        addTag(rson(p), mid + 1, curR, tree[p].tag);
        tree[p].tag = TagT();
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
            push_down(p, curL, curR);
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
                addTag(p, curL, curR, delta);
                return;
            }
            push_down(p, curL, curR);
            int mid = (curL + curR) >> 1;
            if (L <= mid) self(self, lson(p), curL, mid);
            if (R >= mid + 1) self(self, rson(p), mid + 1, curR);
            pull_up(p);
        };
        update(update, 1, 1, size);
    }
};

struct Info {
    i64 val;
    Info() = default; //* 无参初始化（重置时候用）
    Info(i64 v) : val(v) {} //? 从其他类型转换（Build时候用）

    friend Info operator+(const Info& a, const Info& b) { //* 合并操作，a左b右
        return Info(a.val + b.val);
    }
};

//! Only for LSGT
struct Tag {
    i64 add;
    Tag() : add(0) {} //* 初始化（push_down结束重置时候用）
    Tag(i64 d) : add(d) {} //? 从其他类型转换（Modify时候用）
    bool isVaild() const { //* tag是否生效
        return add != 0;
    }
    void applyTo(Info& info, int l, int r, const Tag& delta) { //* 对代表[l,r]区间的info打上tag
        add += delta.add;
        info.val += delta.add * (r - l + 1);
    }
};

//! Only for SGT
struct Delta {
    i64 val;
    Delta(i64 v) : val(v) {}
    void applyTo(Info& info) const { 
        info.val += val;
    }
};


int main() {
    std::vector<i64> test = {0, 1, 2, 4, 5, 7};
    LSGT<Info, Tag> A(test);
    std::cout << A.query(1, 3).val << std::endl;
    std::cout << A.query(2, 5).val << std::endl;
    std::cout << A.query(1, 5).val << std::endl;
    A.modify(1, 3, Tag(1));
    std::cout << A.query(1, 3).val << std::endl;
    std::cout << A.query(2, 5).val << std::endl;
    std::cout << A.query(1, 5).val << std::endl;
}

/*struct SumInfo {
    modint val;
    SumInfo() : val(0) {} // 初始化（重置时候用）
    SumInfo(modint v) : val(v) {} // 从其他类型转换（Build时候用）
    SumInfo mergeWith(const SumInfo& other) const { // 合并操作
        return SumInfo(val + other.val);
    }
};

struct AddMulTag {
    modint add, mul;
    AddMulTag() : add(0), mul(1) {} // 初始化（重置时候用）
    bool isVaild() const { // tag是否生效
        return add != modint(0) || mul != modint(1);
    }
    void applyTo(SumInfo& info, int l, int r, AddMulTag delta) { // 对代表[l,r]区间的info打上tag
        mul *= delta.mul;
        add *= delta.mul;
        add += delta.add;
        info.val *= delta.mul;
        info.val += delta.add * (r - l + 1);
    }
};*/