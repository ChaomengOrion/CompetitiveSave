#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

/*std::vector<int> compute_prefix_function(const std::string& s) {
    int n = s.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

std::pair<int, int> find_max_prefix_substring(const std::string& A, const std::string& B) {
    std::string combined = B + '#' + A;
    std::vector<int> pi = compute_prefix_function(combined);
    int max_prefix_length = 0;
    int start_index = -1;

    for (int i = B.size() + 1; i < combined.size(); i++) {
        if (pi[i] > max_prefix_length) {
            max_prefix_length = pi[i];
            start_index = i - 2 * B.size();
        }
    }

    return {start_index, max_prefix_length};
}*/

void solve() {
    std::string B1;
    std::cin >> B1;
    std::string B2;
    for (int i = 1; i < B1.size(); i++) {
        B2 += B1[i] == '0' ? '1' : '0';
    }
    int zero = B2.find_first_of('1');
    std::cout << "1 " << B1.size() << ' ';
    if (zero == B2.npos) {
        std::cout << "1 1" << std::endl;
    } else {
        std::string need = B2.substr(zero);
        int maxL = -1, maxP = 0;
        for (int i = 0; i < B1.size() - need.size() + 1; i++) {
            if (B1[i] == need[0]) {
                int p = 1;
                while (p < need.size() && i + p < B1.size() && B1[i + p] == need[p]) {
                    p++;
                }
                if (p > maxP) {
                    maxP = p;
                    maxL = i + 1;
                }
            }
        }
        std::cout << maxL << ' ' << maxL + need.size() - 1 << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}