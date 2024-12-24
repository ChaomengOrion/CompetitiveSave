#include <bits/stdc++.h>
#include <bits/extc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>,
                    __gnu_pbds::rb_tree_tag,
                    __gnu_pbds::tree_order_statistics_node_update> a;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}