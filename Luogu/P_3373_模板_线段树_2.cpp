#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

int MOD;

template <typename T>
concept CanBit = requires(T x) { x >>= 1; };
//template <int MOD>
struct modint {
    int val;
    static int norm(const int& x) { return x < 0 ? x + MOD : x; }
    //static constexpr int get_mod() { return MOD; }
    modint inv() const {
        assert(val);
        int a = val, b = MOD, u = 1, v = 0, t;
        while (b > 0) t = a / b, std::swap(a -= t * b, b), std::swap(u -= t * v, v);
        assert(b == 1);
        return modint(u);
    }
    modint() : val(0) {}
    modint(const int& m) : val(norm(m)) {}
    modint(const i64& m) : val(norm(m % MOD)) {}
    modint operator-() const { return modint(norm(-val)); }
    bool operator==(const modint& o) { return val == o.val; }
    bool operator<(const modint& o) { return val < o.val; }
    modint& operator+=(const modint& o) { return val = (1LL * val + o.val) % MOD, *this; }
    modint& operator-=(const modint& o) { return val = norm(1LL * val - o.val), *this; }
    modint& operator*=(const modint& o) { return val = static_cast<int>(1LL * val * o.val % MOD), *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }
    modint& operator^=(const modint& o) { return val ^= o.val, *this; }
    modint& operator>>=(const modint& o) { return val >>= o.val, *this; }
    modint& operator<<=(const modint& o) { return val <<= o.val, *this; }
    modint operator-(const modint& o) const { return modint(*this) -= o; }
    modint operator+(const modint& o) const { return modint(*this) += o; }
    modint operator*(const modint& o) const { return modint(*this) *= o; }
    modint operator/(const modint& o) const { return modint(*this) /= o; }
    modint operator^(const modint& o) const { return modint(*this) ^= o; }
    modint operator>>(const modint& o) const { return modint(*this) >>= o; }
    modint operator<<(const modint& o) const { return modint(*this) <<= o; }
    friend std::istream& operator>>(std::istream& is, modint& a) {
        i64 v;
        return is >> v, a.val = norm(v % MOD), is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint& a) { return os << a.val; }
    friend std::string tostring(const modint& a) { return std::to_string(a.val); }
    template <CanBit T>
    friend modint qpow(const modint& a, const T& b) {
        assert(b >= 0);
        modint x = a, res = 1;
        for (T p = b; p; x *= x, p >>= 1)
            if (p & 1) res *= x;
        return res;
    }
};

template<typename InfoT, typename TagT> //requires InfoType<InfoT> && TagType<TagT, InfoT>
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

    void addTag(int p, int curL, int curR, const TagT& delta) { //* 给代表[l,r]区间的Info打Tag
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

    void modify(int L, int R, const TagT& delta) {
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

struct SumInfo {
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
};

void solve()
{
    int N, Q;
    std::cin >> N >> Q >> MOD;
    std::vector<modint> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    SGT<SumInfo, AddMulTag> sgt(arr);
    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            AddMulTag delta;
            delta.mul = k;
            sgt.modify(x, y, delta);
        } else if (op == 2) {
            int x, y, k;
            std::cin >> x >> y >> k;
            AddMulTag delta;
            delta.add = k;
            sgt.modify(x, y, delta);
        } else {
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