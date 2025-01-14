#include <bits/stdc++.h>

using i64 = long long;
using d64 = double;
using d128 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template<class T, class G> struct Vector2Base {
    T x, y;
    constexpr Vector2Base()
        : Vector2Base(T{}, T{}) {}
    constexpr Vector2Base(T x, T y)
        : x{x}
        , y{y} {}

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

template<class T, class G> G dis2(Vector2Base<T, G> a, Vector2Base<T, G> b = Vector2Base<T, G>(0, 0)) {
    Vector2Base<T, G> p = a - b;
    return p * p;
}

template<class Vector2> auto dis(Vector2 a, Vector2 b = Vector2(0, 0)) {
    return std::sqrt(dis2(a, b));
}

template<class Vector2> int sgn(Vector2 p) {
    if (p.x < 0 or p.x == 0 and p.y > 0) { //? 23象限+正y轴（左）
        return 1;
    } else {
        return 0; //? 14象限+负y轴（右）
    }
}

//* 按极角排序，4123象限顺序
template<class Vector2> bool polarCmp(Vector2 p, Vector2 q) {
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
template<class G = d128, class Vector2> G getAngle(Vector2 a, Vector2 b, Vector2 o = Vector2(0, 0)) {
    auto A = a - o, B = b - o;
    return std::atan2<G>(A % B, A * B);
}

//* 把角度缩到范围[0,π]
template<class G> G normAngle(G angle) {
    angle = std::abs(angle);
    return std::min(angle, 2 * std::numbers::pi_v<G> - angle);
}

using Vector2 = Vector2Base<int, i64>;

void solve() {
    int N;
    std::cin >> N;
    std::vector<std::pair<Vector2, int>> points(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> points[i].first;
        points[i].second = i;
    }
    std::sort(points.begin() + 1, points.end(), [](auto& a, auto& b) {
        return polarCmp(a.first, b.first);
    });
    d128 min_ang = INFINITY; std::pair<int, int> min_i;
    for (int i = 1; i <= N; i++) {
        d128 ang = normAngle(getAngle(points[i].first, points[i % N + 1].first));
        if (ang < min_ang) {
            min_ang = ang;
            min_i = std::make_pair(points[i].second, points[i % N + 1].second);
        }
    }
    std::cout << min_i.first << ' ' << min_i.second << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}