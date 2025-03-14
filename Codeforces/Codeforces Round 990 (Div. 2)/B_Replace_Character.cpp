#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    std::map<char, int> cntMap;
    for (int i = 0; i < N; i++) {
        cntMap[S[i]]++;
    }
    std::multimap<int, char> cnt;
    for (auto [k, v] : cntMap) {
        cnt.insert({v, k}); // ! TEST
    }
    char min = cnt.begin()->second;
    char max = prev(cnt.end())->second;
    S[S.find_first_of(min)] = S[S.find_first_of(max)];
    std::cout << S << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}