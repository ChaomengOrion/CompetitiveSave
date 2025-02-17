#include <bits/stdc++.h>
using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n), b(m);
    for(auto &x : a) std::cin >> x;
    for(auto &x : b) std::cin >> x;
    
    std::multiset<i64> set_a(a.begin(), a.end());
    std::multiset<i64> set_b(b.begin(), b.end());
    
    // 如果b中的元素总和不等于a中的元素总和，直接返回No
    i64 sum_a = 0, sum_b = 0;
    for(auto x : a) sum_a += x;
    for(auto x : b) sum_b += x;
    if(sum_a != sum_b) {
        std::cout << "No\n";
        return;
    }
    
    // 从b中最大的元素开始，尝试拆分
    while(!set_b.empty()) {
        if (set_b.size() > set_a.size()) {
            // 无法拆分
            std::cout << "No\n";
            return;
        }
        i64 current = *set_b.rbegin();
        set_b.erase(--set_b.end());
        
        // 如果当前元素在a中存在，直接匹配
        auto it = set_a.find(current);
        if(it != set_a.end()) {
            set_a.erase(it);
            continue;
        }
        
        // 尝试拆分当前元素成两个相差不超过1的数
        if(current == 1) {
            // 无法拆分
            std::cout << "No\n";
            return;
        }
        // 拆分为floor(current/2)和 ceil(current/2)
        i64 x = current / 2;
        i64 y = current - x;
        if(abs(x - y) > 1) {
            std::cout << "No\n";
            return;
        }
        set_b.insert(x);
        set_b.insert(y);
    }
    
    // 最后检查a是否全部匹配
    if(set_a.empty()) std::cout << "Yes\n";
    else std::cout << "No\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}