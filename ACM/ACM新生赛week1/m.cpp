#include <iostream>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::cout << 1 << ' ' << N - 1 << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}