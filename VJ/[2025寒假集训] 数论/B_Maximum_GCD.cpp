#include <bits/stdc++.h>

using i64 = long long;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    std::string line;
    std::cin.ignore();
    std::getline(std::cin, line);
    std::istringstream s(line);
    std::vector<int> inp;
    inp.reserve(100);
    int x;
    while (s >> x) {
        inp.push_back(x);
    }
    
    int ans = 0;
    for (int i = 0; i < inp.size() - 1; i++) {
        for (int j = i + 1; j < inp.size(); j++) {
            ans = std::max(ans, gcd(inp[i], inp[j]));
        }
    }
    std::cout << ans << ' ';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}