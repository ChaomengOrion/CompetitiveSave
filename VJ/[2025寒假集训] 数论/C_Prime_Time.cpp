#include <bits/stdc++.h>

using i64 = long long;
using d64 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int N = 10000;

bool isPrime(int num)
{
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    int tmp = sqrt(num);
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

void solve() {
    std::vector<bool> isP(N + 1, true);
    
    for (int i = 0; i <= N; i++) {
        isP[i] = isPrime(i * i + i + 41);
    }

    std::vector<int> pre(N + 2, 0);
    for (int i = 0; i <= N; i++) {
        pre[i + 1] = pre[i] + isP[i];
    }

    int a, b;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> a >> b) {
        std::cout << 100.0l * static_cast<d64>(pre[b + 1] - pre[a]) / static_cast<d64>(b - a + 1) + 1e-8 << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}