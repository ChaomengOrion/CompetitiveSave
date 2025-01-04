#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;


template<class InfoT, class TagT>
class SGT {
public:
    struct node {
        InfoT info = InfoT();
        TagT tag = TagT();
    };
    std::vector<node> tree;
    int size;

    inline int lson(int p) { //* 左子节点
        return p << 1;
    }

    inline int rson(int p) { //* 右子节点
        return p << 1 | 1;
    }

    void addTag(int p, int curL, int curR, TagT delta) { //* 给代表[l,r]区间的Info打Tag
        //LOG("taged: " << curL << ',' << curR << " delta:" << delta)
        tree[p].tag.applyTo(tree[p].info, curL, curR, delta);
    }

    void push_up(int p) { //*用子节点Info更新父节点
        tree[p].info = tree[lson(p)].info.mergeWith(tree[rson(p)].info);
    }

    void push_down(int p, int curL, int curR) { //* 下传Tag
        if (!tree[p].tag.isVaild()) return;
        int mid = (curL + curR) >> 1;
        addTag(lson(p), curL, mid, tree[p].tag);
        addTag(rson(p), mid + 1, curR, tree[p].tag);
        tree[p].tag = TagT();
    }
    
    template<class T>
    SGT(std::vector<T>& source) {
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
            push_up(p);
        };
        build(build, 1, 1, size);
    }
    
    InfoT query(int L, int R) {
        auto search = [&](auto&& self, int p, int curL, int curR) -> InfoT {
            node& cur = tree[p];
            if (L <= curL && curR <= R) return cur.info;
            push_down(p, curL, curR);
            InfoT res = InfoT();
            int mid = (curL + curR) >> 1; //? [curL, mid], [mid+1, curR]中一定有至少一个与[L, R]有交集
            if (L <= mid) res = res.mergeWith(self(self, lson(p), curL, mid));
            if (R >= mid + 1) res = res.mergeWith(self(self, rson(p), mid + 1, curR));
            return res;
        };
        return search(search, 1, 1, size);
    }

    void modify(int L, int R, TagT delta) {
        auto update = [&](auto&& self, int p, int curL, int curR) -> void {
            //LOG(curL << ',' << curR)
            if (L <= curL && curR <= R) {
                addTag(p, curL, curR, delta);
                return;
            }
            push_down(p, curL, curR);
            int mid = (curL + curR) >> 1;
            if (L <= mid) self(self, lson(p), curL, mid);
            if (R >= mid + 1) self(self, rson(p), mid + 1, curR);
            push_up(p);
        };
        update(update, 1, 1, size);
    }
};


struct Info {
    i64 val;
    Info() : val(0) {} // 初始化（重置时候用）
    Info(i64 v) : val(v) {} // 从其他类型转换（Build时候用）
    Info mergeWith(const Info& other) const { // 合并操作
        return Info(val + other.val);
    }
};

struct Tag {
    i64 add;
    Tag() : add(0) {} // 初始化（重置时候用）
    Tag(i64 d) : add(d) {} // 从其他类型转换（Modify时候用）
    bool isVaild() const { // tag是否生效
        return add != 0;
    }
    void applyTo(Info& info, int l, int r, Tag delta) { // 对代表[l,r]区间的info打上tag
        add += delta.add;
        info.val += delta.add * (r - l + 1);
    }
};

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<i64> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    SGT<Info, Tag> sgt(arr);
    while (M--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            sgt.modify(x, y, k);
        } else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            std::cout << sgt.query(x, y).val << std::endl;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}