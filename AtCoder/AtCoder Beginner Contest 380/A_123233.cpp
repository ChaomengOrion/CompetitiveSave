#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::string S;
    std::cin >> S;
    std::map<char, int> map;
    for (int i = 0; i < S.size(); i++) {
        map[S[i]]++;
    }
    bool ok = map['1'] == 1 && map['2'] == 2 && map['3'] == 3;
    std::cout << (ok ? "Yes" : "No") << std::endl;
    
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}