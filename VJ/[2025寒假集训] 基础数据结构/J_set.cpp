#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct range {
    range() = default;
    range(int l, int r) : l(l), r(r) {}
    int l, r;
    friend bool operator<(const range& a, const range& b) {
        return a.r < b.l;
    }
};

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::set<range> set;
    set.emplace(1, N);
    std::stack<int> lastD;
    while (M--) {
        char type;
        std::cin >> type;
        if (type == 'D') {
            int pos;
            std::cin >> pos;
            lastD.push(pos);
            auto it = set.find(range(pos, pos));
            if (it != set.end()) {
                range old = *it;
                set.erase(it);
                if (pos > old.l) set.emplace(old.l, pos - 1);
                if (pos < old.r) set.emplace(pos + 1, old.r);
            }
        } else if (type == 'Q') {
            int pos;
            std::cin >> pos;
            auto it = set.find(range(pos, pos));
            if (it != set.end()) {
                const range& r = *it;
                std::cout << r.r - r.l + 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }
        } else {
            int pos = lastD.top(); lastD.pop();
            auto itl = set.find(range(pos - 1, pos - 1));
            auto itr = set.find(range(pos + 1, pos + 1));
            if (itl != set.end() && itr != set.end()) {
                range oldl = *itl;
                range oldr = *itr;
                set.erase(itl);
                set.erase(itr);
                set.emplace(oldl.l, oldr.r);
            } else if (itl != set.end()) {
                range oldl = *itl;
                set.erase(itl);
                oldl.r++;
                set.emplace(oldl);
            } else if (itr != set.end()) {
                range oldr = *itr;
                set.erase(itr);
                oldr.l--;
                set.emplace(oldr);
            } else {
                set.emplace(pos, pos);
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}