#include <bits/stdc++.h>
#include <bits/extc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>,
                    __gnu_pbds::rb_tree_tag,
                    __gnu_pbds::tree_order_statistics_node_update> a;
    
                    int dd = 3;
                    int& ddr = dd;
                    int&& ddrr = 3;
                    auto dda = ddrr;
                    auto [a1, b1, c1] = std::tie(dd, ddr, dd);
                    auto [a2, b2, c2] = std::forward_as_tuple(dd, ddr, 3.3);
                    auto ttt = std::tie(dd, ddr, dd);
                    std::tie(dd, ddr, dd) = ttt;
                    std::tie(dd, ddr, dd) = std::tie(a1, a1, c2);
                    std::tuple(dd, ddr, dd) = std::tie(a1, a1, c2);
                    std::tuple(dd, ddr, dd) = std::tuple(a1, a1, c2);
                    std::tie(dd, ddr, dd) = std::tuple(a1, a1, c2);
            
                    int vvv = 33;
                    std::vector<std::reference_wrapper<int>> test;
                    int &vvvr = vvv; 
                    test.push_back(vvv);
                    test.push_back(vvvr);
                    auto ccc = std::ref(vvv);
                    test.push_back(ccc);
                    test.push_back(std::forward<int&>(vvv));
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}