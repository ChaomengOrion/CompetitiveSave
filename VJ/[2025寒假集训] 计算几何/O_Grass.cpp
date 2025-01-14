#include <bits/stdc++.h>

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

using i64 = long long;
using d64 = double;
using d128 = long double;

template<class T, class G> struct Vector2Base {
    T x, y;
    constexpr Vector2Base() : Vector2Base(T(), T()) {}
    constexpr Vector2Base(T x, T y) : x(x), y(y) {}

    //* 运算
    constexpr Vector2Base operator+(Vector2Base a) const { return Vector2Base(x + a.x, y + a.y); }
    constexpr Vector2Base operator-(Vector2Base a) const { return Vector2Base(x - a.x, y - a.y); }
    constexpr Vector2Base operator-() const { return Vector2Base(-x, -y); }
    constexpr G operator*(Vector2Base a) const { return (G)x * a.x + (G)y * a.y; }
    constexpr G operator%(Vector2Base a) const { return (G)x * a.y - (G)y * a.x; }
    constexpr Vector2Base rotate() const { return Vector2Base(-y, x); } //* 逆90度
    template<class F> constexpr Vector2Base rotate(F theta) const {
        Vector2Base b(std::cos(theta), std::sin(theta));
        return Vector2Base(x * b.x - y * b.y, x * b.y + y * b.x);
    }
    constexpr friend Vector2Base operator*(const T& a, Vector2Base b) { return Vector2Base(a * b.x, a * b.y); }

    //* 比较
    constexpr bool operator<(Vector2Base a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
    constexpr bool operator>(Vector2Base a) const {
        if (x == a.x) return y > a.y;
        return x > a.x;
    }
    constexpr bool operator<=(Vector2Base a) const {
        if (x == a.x) return y <= a.y;
        return x <= a.x;
    }
    constexpr bool operator>=(Vector2Base a) const {
        if (x == a.x) return y >= a.y;
        return x >= a.x;
    }
    constexpr bool operator==(Vector2Base a) const { return x == a.x && y == a.y; }
    constexpr bool operator!=(Vector2Base a) const { return x != a.x || y != a.y; }

    //* 输入输出
    friend std::istream& operator>>(std::istream& in, Vector2Base& p) { return in >> p.x >> p.y; }
    friend std::ostream& operator<<(std::ostream& ot, Vector2Base p) {
        return ot << p.x << " " << p.y;
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
        return 0; //? 14象限+负y轴（右）
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

//* 计算∠AOB(弧度)
template<class Float = d128> Float getAngle(Vector2 a, Vector2 b, Vector2 o = Vector2(0, 0)) {
    Vector2 A = a - o, B = b - o;
    return std::atan2<Float>(A % B, A * B);
}

//* 把角度缩到范围[0,π]
template<class Float> Float normAngle(Float angle) {
    angle = std::abs(angle);
    return std::min(angle, 2 * std::numbers::pi_v<Float> - angle);
}


//* 点距
template<class Float = d128> Float dis(Vector2 a, Vector2 b = Vector2(0, 0)) {
    return std::sqrt<Float>(dis2(a, b));
}

/* ============Line============== */
//* 点A是否在*直线*BC上
bool onLine(Vector2 a, Vector2 b, Vector2 c) {
    b = b - a;
    c = c - a;
    return b % c == 0;
}

//* 点A是否在*线段*BC上
bool onSeg(Vector2 a, Vector2 b, Vector2 c) {
    b = b - a;
    c = c - a;
    return b % c == 0 and b * c <= 0;
}

//* 点A到*直线*BC的距离
template<class Float = d128> Float disToLine(Vector2 a, Vector2 b, Vector2 c) {
    Vector2 v1 = b - c, v2 = a - c;
    return std::abs<Float>(v1 % v2) / std::sqrt<Float>(v1 * v1);
}

//* 点A到*线段*BC的距离
template<class Float = d128> Float disToSeg(Vector2 a, Vector2 b, Vector2 c) {
    if ((a - b) * (c - b) <= 0 or (a - c) * (b - c) <= 0) {
        return std::min<Float>(dis<Float>(a, b), dis<Float>(a, c));
    }
    return disToLine<Float>(a, b, c);
}

//* 点A在直线BC上的投影点
Vector2 foot(Vector2 a, Vector2 b, Vector2 c) {
    Vector2 u = a - b, v = c - b;
    return b + (u * v) / (v * v) * v;
}

//* 点A关于直线BC的对称点
Vector2 symmetry(Vector2 a, Vector2 b, Vector2 c) {
    Vector2 ft = foot(a, b, c);
    return 2 * ft - a;
}

//* 直线AB和直线CD的交点
Vector2 cross(Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
    Vector2 v = c - d;
    auto sa = v % (a - d), sb = (b - d) % v;
    return sa / (sa + sb) * (b - a) + a;
}

void printAns(std::array<Vector2, 5> ans) {
    for (int i = 0; i < 5; i++) {
        bool ok = true;
        std::vector<Vector2> lines;
        for (int j = 0; j < 5; j++) {
            if (j == i) continue;
            lines.push_back(ans[j] - ans[i]);
        }
        for (int m = 0; m < 3; m++) {
            for (int n = m + 1; n < 4; n++) {
                if (lines[m] % lines[n] == 0 and lines[m] * lines[n] > 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok) continue;
        std::cout << ans[i] << std::endl;
        for (int j = 0; j < 5; j++) {
            if (j == i) continue;
            std::cout << ans[j] << std::endl;
        }
        return;
    }
    assert(0);
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<Vector2> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i];
    }
    if (N < 5) {
        std::cout << "NO" << std::endl;
        return;
    }
    Vector2 A = points[0], B = points[1];
    std::vector<Vector2> outline;
    std::vector<Vector2> other;

    for (int i = 2; i < N; i++) {
        if (outline.empty() and !onLine(points[i], A, B)) {
            outline.push_back(points[i]);
        } else {
            other.push_back(points[i]);
        }
        if (!outline.empty() and other.size() >= 2) break;
    }

    if (!outline.empty()) {
        std::cout << "YES" << std::endl;
        printAns({A, B, outline[0], other[0], other[1]});
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}