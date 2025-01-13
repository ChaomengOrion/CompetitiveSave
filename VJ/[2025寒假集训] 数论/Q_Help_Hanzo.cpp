#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int N = std::sqrt(INT_MAX);

std::vector<int> prime(N + 1); //? 可小于 N，约lnN

//* 线性欧拉筛 O(N)
void euler_sieve(int N) {
    std::vector<bool> vis(N + 1);
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] > N) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < static_cast<int>(prime.size()); i++) {
        if (!prime[i]) {
            prime.resize(i);
            break;
        }
    }
}

/*
* 对合数打上标记
* 在L-R的范围呢用已求出的质数筛出其中的合数，打上标记
* L-R内没有打标记的元素即为素数
*/
void solve() {
    static int case_id = 0;
    i64 L, R;
    std::cin >> L >> R;
    std::vector<bool> isSafe(R - L + 1, true);
    if (L == 1) {
        isSafe[0] = false;
    }
    for (int i = 0; i < static_cast<int>(prime.size()); i++) {
        i64 p = prime[i];
        for (i64 x = std::max(2LL, (L + p - 1) / p) * p; x <= R; x += p) {
            isSafe[x - L] = false;
        }
    }
    int safeCnt = 0;
    for (int i = 0; i < R - L + 1; i++) {
        safeCnt += isSafe[i];
    }
    //std::cout << safeCnt << std::endl;
    std::cout << "Case " << ++case_id << ": " << safeCnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    euler_sieve(N);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}