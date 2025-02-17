#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

int get1(int d) {
    return (d + 10 - 7) % 10;
}

// [nine, nine + t - 1]
int get_cost2(i64 nine, int t) {
    LOG(nine)
    int cost = 0;
    i64 base = 9999999999;
    while (nine > 0) {
        cost++;
        while (base > nine + t - 1) {
            base /= 10;
        }
        nine -= base;
    }
    LOG(cost)
    return cost;
}

int get_cost(i64 nine, i64 t) {
    if (t * 10 + 9 <= nine) t = t * 10 + 9;
    LOG(nine << " " << t)
    return (nine + t - 1) / t;
}

// t是temp位数
int getn(int d, i64 temp, i64 t) {
    if (d == 7) return 0;
    int ans = INT_MAX;
    if (d < 7) {
        ans = get_cost2(7 * t - temp, t);
    }
    for (int i = 1; i <= 9; i++) {
        ans = std::min(ans, get_cost2((i * 10 + 7) * t - temp, t));
    }
    /*if (d > 7) {
        ans = get_cost(17 * t - temp, t);
    }*/
    LOG(temp << " cost: " << ans)
    return ans;
}

void solve() {
    int N;
    std::cin >> N;
    i64 temp = 0; i64 cnt = 1;
    int ans = INT_MAX;
    //* 个位
    int d1 = N % 10; N /= 10;
    temp += d1 * cnt; cnt *= 10;
    ans = std::min(ans, get1(d1));
    while (N > 0) {
        int d = N % 10; N /= 10;
        temp += d * cnt;
        if (temp > 9) ans = std::min(ans, getn(d, temp, cnt));
        cnt *= 10;
    }   
    std::cout << std::min(7, ans) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}