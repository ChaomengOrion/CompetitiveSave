#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> stones(N + 1);
    for(int i = 1; i <= N; i++) {
        std::cin >> stones[i];
    }
    int S;
    std::cin >> S;
    int pos = (S + K - 1) % N + 1;
    int min = stones[S], minPos = S;
    while(pos != S) {
        stones[pos]--;
        if (stones[pos] < min) {
            min = stones[pos];
            minPos = pos;
        }
        pos = (pos + K - 1) % N + 1;
    }
    std::cout << minPos << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}