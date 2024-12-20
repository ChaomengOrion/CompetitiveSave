#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::priority_queue<int> A;
    std::priority_queue<int, std::vector<int>, std::greater<>> B;
    for(int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        A.push(temp);
    }
    for(int i = 0; i < M; i++) {
        int temp;
        std::cin >> temp;
        B.push(temp);
    }
    while (!A.empty() && !B.empty())
    {
        int a = A.top(); A.pop();
        int b = B.top(); B.pop();

        if (a > b) {
            A.push(a - b);
        } else if (a < b) {
            B.push(b - a);
        }
    }
    if (A.empty() && B.empty()) {
        std::cout << "draw" << std::endl;
    } else if (A.empty()) {
        std::cout << "Bob" << std::endl;
    } else {
        std::cout << "Alice" << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}