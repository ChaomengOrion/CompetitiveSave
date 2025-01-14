#include <bits/stdc++.h>

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

using i64 = long long;
using d64 = double;
using d128 = long double;

template<class T, class G> struct Vector2Base {
    T x, y;
    Vector2Base() : Vector2Base(T(), T()) {}
    Vector2Base(T x, T y) : x(x), y(y) {}

    //* 运算
    Vector2Base operator+(Vector2Base a) const { return Vector2Base(x + a.x, y + a.y); }
    Vector2Base operator-(Vector2Base a) const { return Vector2Base(x - a.x, y - a.y); }
    Vector2Base operator-() const { return Vector2Base(-x, -y); }
    G operator*(Vector2Base a) const { return (G)x * a.x + (G)y * a.y; }
    G operator%(Vector2Base a) const { return (G)x * a.y - (G)y * a.x; }
    Vector2Base rotate() const { return Vector2Base(-y, x); } //* 逆90度
    template<class F> Vector2Base rotate(F theta) const {
        Vector2Base b(std::cos(theta), std::sin(theta));
        return Vector2Base(x * b.x - y * b.y, x * b.y + y * b.x);
    }
    friend Vector2Base operator*(const T& a, Vector2Base b) { return Vector2Base(a * b.x, a * b.y); }

    //* 比较
    bool operator<(Vector2Base a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
    bool operator>(Vector2Base a) const {
        if (x == a.x) return y > a.y;
        return x > a.x;
    }
    bool operator<=(Vector2Base a) const {
        if (x == a.x) return y <= a.y;
        return x <= a.x;
    }
    bool operator>=(Vector2Base a) const {
        if (x == a.x) return y >= a.y;
        return x >= a.x;
    }
    bool operator==(Vector2Base a) const { return x == a.x && y == a.y; }
    bool operator!=(Vector2Base a) const { return x != a.x || y != a.y; }

    //* 输入输出
    friend std::istream& operator>>(std::istream& in, Vector2Base& p) { return in >> p.x >> p.y; }
    friend std::ostream& operator<<(std::ostream& ot, Vector2Base p) {
        return ot << '(' << p.x << ", " << p.y << ')';
    }
};

//* 点距平方
template<class T, class G> G dis2(Vector2Base<T, G> a, Vector2Base<T, G> b = Vector2Base<T, G>(0, 0)) {
    Vector2Base<T, G> p = a - b;
    return p * p;
}

using Vector2 = Vector2Base<int, i64>;

/* ================= */

//* 象限确认
int sgn(Vector2 p) {
    if (p.x < 0 or p.x == 0 and p.y > 0) { //? 23象限+正y轴（左）
        return 1;
    } else {
        return 0; //? 14象限+负y轴+原点（右）
    }
}

//* 按极角排序，4123象限顺序
bool polarCmp(Vector2 p, Vector2 q) {
    if (sgn(p) == sgn(q)) {
        if (p % q == 0) {
            return dis2(p) < dis2(q); // 重合返回短的
        } else {
            return p % q > 0; // true代表p在q顺时针方向
        }
    } else {
        return sgn(p) < sgn(q);
    }
}

/*====================*/

using Vertexs = std::vector<Vector2>;

//* Graham法求凸包
Vertexs getConvexHull(Vertexs S) {
    Vector2 base = *std::min_element(S.begin(), S.end()); // 以左下角为原点
    for (int i = 0; i < (int)S.size(); i++) {
        S[i] = S[i] - base;
    }
    std::sort(S.begin(), S.end(), polarCmp); // 按极角排序
    int e = S.size() - 1;
    while (e > 1) {
        if (S[e] % S.back() == 0) e--;
        else break;
    }
    std::reverse(S.begin() + e + 1, S.end());
    std::deque<Vector2> Q;
    Q.push_back(S[0]);
    Q.push_back(S[1]);
    for (int i = 2; i < (int)S.size(); i++) {
        Vector2 B = Q.back(); Q.pop_back(); Vector2 A = Q.back(); // B后A前
        while ((S[i] - B) % (B - A) > 0) {
            B = A; // 删A
            Q.pop_back();
            A = Q.back();
        }
        Q.push_back(B);
        Q.push_back(S[i]);
    }
    Vertexs ans(Q.size());
    int pos = 0;
    while (!Q.empty()) {
        ans[pos++] = Q.front() + base;
        Q.pop_front();
    }
    return ans;
}

void solve() {
    int N;
    std::cin >> N;
    Vertexs vs(N);
    for (int i = 0; i < N; i++) {
        char type;
        std::cin >> vs[i] >> type;
    }
    Vertexs hull = getConvexHull(vs);
    std::cout << hull.size() << std::endl;
    for (int i = 0; i < (int)hull.size(); i++) {
        std::cout << hull[i].x << ' ' << hull[i].y << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}