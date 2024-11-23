#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

char get(char c) {
    if ('a' <= c && c <= 'z') {
        c = c - 'a' + 'A';
    }
    else if ('A' <= c && c <= 'Z') {
        c = c - 'A' + 'a';
    }
    return c;
}

int down(i64 x, int pre_cnt) {
    if (x == 1) return pre_cnt;
    i64 d = log2l(x - 1);
    i64 l = 1LL << d;
    assert(l > 0);
    return down(x - l, pre_cnt + 1);
}

void solve() {
    std::string S;
    i64 Q;
    std::cin >> S >> Q;
    i64 size = S.size();
    while (Q--) {
        i64 K;
        std::cin >> K;
        std::cout << ((down((K + size - 1) / size, 0) & 1 ^ 1) ? S[(K - 1) % size] : get(S[(K - 1) % size])) << ' ';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}