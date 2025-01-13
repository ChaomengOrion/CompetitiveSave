#include <bits/stdc++.h>

using i64 = long long;

// 调试宏，保留但可选
#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; \
    for (int _i = 0; _i < (_size); _i++) { \
        std::cerr << (_vec)[_i]; \
        if (_i != (_size) - 1) std::cerr << ", "; \
    } \
    std::cerr << ']' << std::endl;

// 全局质数筛选器，避免在每次测试用例中重复计算
std::vector<bool> sieve;

// 初始化埃拉托斯特尼筛法
void initialize_sieve(int max_limit) {
    sieve.assign(max_limit + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= max_limit; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

void solve() {
    static bool is_initialized = false;
    if (!is_initialized) {
        // 初始化筛选器，假设 n <= 1e7
        initialize_sieve(10000000);
        is_initialized = true;
    }

    static int cnt = 0; // 案例编号
    int N;
    std::cin >> N;

    int ans = 0;
    // 只需遍历到 n/2，避免重复
    for(int a = 2; a <= N / 2; ++a) {
        if(sieve[a] && sieve[N - a]) {
            ans++;
        }
    }

    std::cout << "Case " << ++cnt << ": " << ans << std::endl;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; 
    while (t--) solve();
    return 0;
}