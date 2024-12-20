#include <iostream>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}