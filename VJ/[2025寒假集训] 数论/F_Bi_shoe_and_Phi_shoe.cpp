#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int MAXN = 1.1e6;

std::vector<int> phi(MAXN + 1);
std::map<int, int> min_map;

//* 预处理求欧拉函数
void euler_pre(int N) {
    std::iota(phi.begin() + 1, phi.end(), 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            phi[j] -= phi[i];
        }
    }
}

void solve() {
    static int cast_cnt = 0;
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    i64 sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        for(int j = a + 1; j <= MAXN;j++){
            if(phi[j] >= a) {
                sum += j;
                break;
            }
        }
    }
    std::cout << "Case " << ++cast_cnt << ": " << sum << " Xukha" << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    euler_pre(MAXN);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}