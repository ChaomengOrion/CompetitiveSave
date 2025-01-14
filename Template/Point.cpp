#include <bits/stdc++.h>

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

//* 计算∠AOB(弧度)
template<class Float = d128> Float getAngle(Vector2 a, Vector2 b, Vector2 o = Vector2(0, 0)) {
    Vector2 A = a - o, B = b - o;
    return std::atan2<Float>(A % B, A * B);
}

//* 把角度缩到范围[0,π]
template<class Float = d128> Float normAngle(Float angle) {
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

// 对四个不同的点判断四点共圆
// d在abc外接圆外return 1, 内return -1
template<class Float = d128> int inCircle(Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
    const Float PI = acosl(-1);
    Float ag1 = getAngle(a, b, c), ag2 = getAngle(d, c, b);
    auto sgn = [](Float x) { return x < 0 ? -1 : (x > 0); };
    if (sgn(ag1) == sgn(ag2)) {
        return sgn(PI - std::abs(ag1 + ag2));
    } else {
        return sgn(std::abs(ag1) - std::abs(ag2));
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

    /* 
    ?不删共线点加上
    int e = S.size() - 1;
    while (e > 1) {
        if (S[e] % S.back() == 0) e--;
        else break;
    }
    std::reverse(S.begin() + e + 1, S.end());
    */

    std::deque<Vector2> Q;
    Q.push_back(S[0]);
    Q.push_back(S[1]);
    for (int i = 2; i < (int)S.size(); i++) {
        Vector2 B = Q.back(); Q.pop_back(); Vector2 A = Q.back(); // B后A前
        while ((S[i] - B) % (B - A) >= 0) { //? 不删共线点就去掉等号
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


//! test
int main() {
    int N;
    std::cin >> N;
    Vertexs vs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vs[i];
    }
    Vertexs hull = getConvexHull(vs);
    for (int i = 0; i < (int)hull.size(); i++) {
        std::cout << hull[i] << std::endl;
    }
}