#include <bits/stdc++.h>

int ask(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    std::cout.flush();
    int cnt;
    std::cin >> cnt;
    return cnt;
}

void report(std::string s) {
    std::cout << "! " + s << std::endl;
    std::cout.flush();
}

void solve() {
    int N; // 2≤n≤10E4
    std::cin >> N;
    int last1 = -1;
    std::string ans;
    int pre_cnt = 1;
    for (int pos = N - 1; pos >= 1; pos--) {
        if (last1 == -1) {
            int cnt = ask(pos, N);
            if (cnt > 0) {
                last1 = pos + 1;
                int pass = N - pos + 1;
                for (int i = 0; i < pass - cnt - 1; i++) {
                    ans += '0';
                }
                for (int i = 0; i < cnt; i++) {
                    ans += '1';
                }
                ans += '0';
            } else if (pos == 1) {
                report("IMPOSSIBLE");
                return;
            }
        } else {
            int cnt = ask(pos, last1);
            if (cnt == pre_cnt) {
                ans += '1';
            } else if (cnt == pre_cnt + 1) {
                ans += '0';
                pre_cnt = cnt;
            } else {
                ans += '0';
                last1 = pos + 1;
                pre_cnt = 1;
            }
        }
    }
    std::reverse(ans.begin(), ans.end());
    report(ans);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}