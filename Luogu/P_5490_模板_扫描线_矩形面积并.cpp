#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

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

struct rect {
    int x1, y1, x2, y2;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<rect> rects(N);
    std::vector<int> xs;
    for (int i = 0; i < N; i++) {
        std::cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        xs.push_back(rects[i].x1);
        xs.push_back(rects[i].x2);
    }
    std::sort(xs.begin(), xs.end());
    int et = std::unique(xs.begin(), xs.end()) - xs.begin();
    std::vector<int> i2r(et + 1);
    std::map<int, int> r2i;
    for (int i = 0; i < et; i++) {
        i2r[i + 1] = xs[i];
        r2i[xs[i]] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        rects[i].x1 = r2i[rects[i].x1];
        rects[i].x2 = r2i[rects[i].x2];
    }
    std::vector<std::tuple<int, int, int, bool>> edges;
    for (int i = 0; i < N; i++) {
        edges.emplace_back(rects[i].y1, rects[i].x1, rects[i].x2, true);
        edges.emplace_back(rects[i].y2, rects[i].x1, rects[i].x2, false);
    }
    std::sort(edges.begin(), edges.end());
    LSGT<Info, Tag> sgt();
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}