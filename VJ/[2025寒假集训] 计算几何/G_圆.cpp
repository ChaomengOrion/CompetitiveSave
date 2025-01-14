#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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

struct Circle {
    Vector2 pos;
    int r;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<Circle> circles(N);
    for (int i = 0; i < N; i++) {
        std::cin >> circles[i].pos.x;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> circles[i].pos.y;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> circles[i].r;
    }
    Vector2 A, B;
    std::cin >> A >> B;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool ain = dis2(circles[i].pos, A) < circles[i].r * circles[i].r;
        bool bin = dis2(circles[i].pos, B) < circles[i].r * circles[i].r;
        ans += ain ^ bin;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}